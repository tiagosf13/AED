//
// AED, August 2022 (Tomás Oliveira e Silva)
//
// First practical assignement (speed run)
//
// Compile using either
//   cc -Wall -O2 -D_use_zlib_=0 solution_speed_run.c -lm
// or
//   cc -Wall -O2 -D_use_zlib_=1 solution_speed_run.c -lm -lz
//
// Place your student numbers and names here
//   N.Mec. XXXXXX  Name: XXXXXXX
//


//
// static configuration
//

#define _max_road_size_  800  // the maximum problem size
#define _min_road_speed_   2  // must not be smaller than 1, shouldnot be smaller than 2
#define _max_road_speed_   9  // must not be larger than 9 (only because of the PDF figure)


//
// include files --- as this is a small project, we include the PDF generation code directly from make_custom_pdf.c
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../P02/elapsed_time.h"
#include "make_custom_pdf.c"


//
// road stuff
//

static int max_road_speed[1 + _max_road_size_]; // positions 0.._max_road_size_ [0;800]

static void init_road_speeds(void) // initialize the road speeds (this is the same as in the slides)
{
  double speed;
  int i;

  for(i = 0;i <= _max_road_size_;i++) // positions 0.._max_road_size_ [0;800]
  {
    speed = (double)_max_road_speed_ * (0.55 + 0.30 * sin(0.11 * (double)i) + 0.10 * sin(0.17 * (double)i + 1.0) + 0.15 * sin(0.19 * (double)i)); // the road speed function that generates a random road speed
    max_road_speed[i] = (int)floor(0.5 + speed) + (int)((unsigned int)rand() % 3u) - 1;
    if(max_road_speed[i] < _min_road_speed_)
      max_road_speed[i] = _min_road_speed_;
    if(max_road_speed[i] > _max_road_speed_)
      max_road_speed[i] = _max_road_speed_;
  }
}


//
// description of a solution
//

typedef struct // structure of the solution (it can be the best solution found so far, or the solution that is currently being tested
{
  int n_moves;                         // the number of moves (the number of positions is one more than the number of moves)
  int positions[1 + _max_road_size_];  // the positions (the first one must be zero)
}
solution_t;



//
// the (very inefficient) recursive solution given to the students
//

static solution_t solution_1,solution_1_best; // the current solution and the best solution found so far
static double solution_1_elapsed_time; // time it took to solve the problem
static unsigned long solution_1_count; // effort dispended solving the problem


static boolean solution_1_recursion(int move_number,int position,int speed,int final_position) // first arguments (0, 0, 0, final_position)
{
  //printf("solution_1_recursion(%d,%d,%d,%d)\n",move_number,position,speed,final_position);
  int speed_soma = 0; // sum of the continuous decrementation of the speed through the road

  solution_1.positions[move_number] = position; // add the current position to the solution
  solution_1_count++;

  if (speed == 1 && position == final_position){ // if the speed is 1 and the position is the final position, we have a solution
    if(move_number < solution_1_best.n_moves) // if the solution is better than the best solution found so far, then update the best solution
    {                                        
      solution_1_best = solution_1;
      solution_1_best.n_moves = move_number;
    }
    //printf("encontrou = %d , %d \n", position ,move_number );
    return TRUE;
  }

  if (solution_1_best.positions[move_number] > position){
    return FALSE;
  }


  if (position == final_position){
    return FALSE;
  }

  if(move_number > solution_1_best.n_moves){
    return FALSE;
  }
  
  if(speed > _max_road_speed_ || speed > max_road_speed[position] || speed < 0 || (speed < 1 && position >0)  ){
    return FALSE;
  }



  int positions_left = final_position - position;

  for(int i = speed; i >=1; i--){
      speed_soma += i;
      if (speed > max_road_speed[position+i]){
          return FALSE;
      }
  }

  if(speed_soma > positions_left){
    return FALSE;
  }

  solution_1_recursion(move_number + 1, position + speed, speed+1, final_position);
  solution_1_recursion(move_number + 1, position + speed, speed, final_position);
  solution_1_recursion(move_number + 1, position + speed, speed-1, final_position);
  
  return FALSE;
}

static void solve_1(int final_position) // we pass the final position of the road as an argument
{
  if(final_position < 1 || final_position > _max_road_size_) // verify that the final position is valid
  {
    fprintf(stderr,"solve_1: bad final_position\n");
    exit(1);
  }
  solution_1_elapsed_time = cpu_time(); // start the timer
  solution_1_count = 0ul; // reset the effort counter
  solution_1_best.n_moves = final_position + 100; // set the best solution to an impossible value

  solution_1_recursion(0,0,0,final_position); // call the recursive function (move_number,position,speed,final_position)
  solution_1_elapsed_time = cpu_time() - solution_1_elapsed_time; // stop the timer and calculate the elapsed time
}


//
// example of the slides
//

static void example(void)
{
  int i,final_position;

  srand(0xAED2022);
  init_road_speeds();
  final_position = 30;
  solve_1(final_position);
  make_custom_pdf_file("example.pdf",final_position,&max_road_speed[0],solution_1_best.n_moves,&solution_1_best.positions[0],solution_1_elapsed_time,solution_1_count,"Plain recursion");
  printf("mad road speeds:");
  for(i = 0;i <= final_position;i++)
    printf(" %d",max_road_speed[i]);
  printf("\n");
  printf("positions:");
  for(i = 0;i <= solution_1_best.n_moves;i++)
    printf(" %d",solution_1_best.positions[i]);
  printf("\n");
}


//
// main program
//

int main(int argc,char *argv[argc + 1])
{
# define _time_limit_  3600.0
  int n_mec,final_position,print_this_one;
  char file_name[64];

  // generate the example data
  if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'e' && argv[1][2] == 'x')
  {
    example();
    return 0;
  }
  // initialization
  n_mec = (argc < 2) ? 0xAED2022 : atoi(argv[1]);
  srand((unsigned int)n_mec);
  init_road_speeds();
  // run all solution methods for all interesting sizes of the problem
  final_position = 1;
  solution_1_elapsed_time = 0.0;
  printf("    + --- ---------------- --------- +\n");
  printf("    |                plain recursion |\n");
  printf("--- + --- ---------------- --------- +\n");
  printf("  n | sol            count  cpu time |\n");
  printf("--- + --- ---------------- --------- +\n");

  while(final_position <= _max_road_size_/* && final_position <= 20*/)
  {
    print_this_one = (final_position == 10 || final_position == 20 || final_position == 50 || final_position == 100 || final_position == 200 || final_position == 400 || final_position == 800) ? 1 : 0;
    printf("%3d |",final_position);
    // first solution method (very bad)
    if(solution_1_elapsed_time < _time_limit_)
    {
      solve_1(final_position);
      if(print_this_one != 0)
      {
        sprintf(file_name,"%03d_1.pdf",final_position);
        make_custom_pdf_file(file_name,final_position,&max_road_speed[0],solution_1_best.n_moves,&solution_1_best.positions[0],solution_1_elapsed_time,solution_1_count,"Plain recursion");
      }
      printf(" %3d %16lu %9.3e |",solution_1_best.n_moves,solution_1_count,solution_1_elapsed_time);
    }
    else
    {
      solution_1_best.n_moves = -1;
      printf("                                |");
    }
    // second solution method (less bad)
    // ...


    // done
    printf("\n");
    fflush(stdout);
    // new final_position
    if(final_position < 50)
      final_position += 1;
    else if(final_position < 100)
      final_position += 5;
    else if(final_position < 200)
      final_position += 10;
    else
      final_position += 20;
  }
  printf("--- + --- ---------------- --------- +\n");
  return 0;
# undef _time_limit_
}
