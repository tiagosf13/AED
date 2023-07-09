//
// Tomás Oliveira e Silva, AED, October 2021
//
// example of a generic class (with a template)
//

#include <iostream>

using namespace std;

//
// warning: this code is just an example of how an integer parameter can appear in a class template
//          this is NOT a good way to define the maximum size of a stack!
//          it is FAR better to put max_size as a parameter (with a default value)
//          on the constructor member function of the stack class (do that as a homework exercise)
//          homework: to this!
//

template <typename T,int max_size> //dentro do template estao os tipos genericos, T é o tipo genérico (ou seja, posso definir um stack do tipo que eu quiser, pois T é generico), 
class stack
{
  private:
    T d_data[max_size]; //numero maximo de elementos que podemos por no stack
    int d_size; //numero de elementos que la estao no momento em que criamos o stack
  public:
    stack(void)
    { // constructor
      d_size = 0;
    }

    ~stack(void)
    { // destructor
      if(d_size > 0)
        cerr << "warning: the stack being destroyed is not empty" << endl;
    }

    void push(T v)
    { // put a thing in the stack
      if(d_size >= max_size)
        cerr << "push error: the stack is full" << endl; // nice place to throw an exception!
      else
        d_data[d_size++] = v;
    }

    void put(T v)
    { // same as push
      push(v);
    }

    T pop(void)
    { // get and remove a thing from the too of the stack (last in, first out!)
      T v;

      if(d_size <= 0)
      {
        cerr << "pop error: the stack is empty" << endl; // nice place to throw an exception!
        v = T(0); // this assumes that the compiler knows how to convert an integer to type T
      }
      else
        v = d_data[--d_size]; //aqui alteramos o valor de d_size
      return v;
    }

    T get_value(int index){
      if(index >= d_size){
        cerr << "get_value error: index out of bounds" << endl;
        return T(0);
      }
      return d_data[index];
    }

    T get(void)
    { // same as pop
      return pop();
    }

    int size(void)
    { // return the number of things in the stack
      return d_size;
    }

    T top(void)
    { // get a thing from the top of the stack
      T v;

      if(d_size <= 0)
      {
        cerr << "top error: the stack is empty" << endl; // nice place to throw an exception!
        v = T(0); // this assumes that the compiler knows how to convert an integer to type T
      }
      else
        v = d_data[d_size - 1]; //aqui nao alteramos o valor de d_size, apenas usamos o valor de d_size para aceder ao elemento do array
      return v;
    }
};

int main(void)
{
  stack<int,10> s; // a stack capable of holding 10 integers

  stack<char,5> stack_chars;

  stack<double,30> stack_strings;

  cout << "push: 3" << endl;
  s.push(3);
  cout << "push: 7" << endl;
  s.push(7);
  cout << "pop: " << s.pop() << endl; // should print 7
  cout << "top: " << s.top() << endl; // should print 3
  cout << "pop: " << s.pop() << endl; // should print 3


  cout << "push: 's'" << endl;
  stack_chars.push('t');
  stack_chars.push('i');
  stack_chars.push('a');
  stack_chars.push('g');
  stack_chars.push('o');
  cout << "Values of s: [";
  for (int i = 0; i < stack_chars.size()-1; i++){
    cout << stack_chars.get_value(i) << ",";
  }
  cout << stack_chars.get_value(stack_chars.size()-1) << "]" << endl;
  
  return 0;
}