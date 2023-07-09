//
// Tomás Oliveira e Silva, AED, October 2021
//
// example of function overloading (same function name, different argument numbers and/or data types)
//

#include <iostream>

using std::cout; // make this symbol from the std namespace directly visible

void show(const int i)
{
  cout << "int: "
      << i
      << std::endl;
}

void show(const double d)
{
  cout << "double: "
      << d
      << std::endl;
}

void show(const char *s,const char *h = "string: ") // second argument with default value
{
  cout << h
      << s
      << std::endl;
}

void show(const char c)
{
  cout << "char: "
      << c
      << std::endl;
}

void show(const int *p, const size_t n){
  cout << "array: [";
  for(int i = 0; i < n-1; i++){
      cout << p[i] << ", ";
  }
  cout<< p[n-1] << "]" <<std::endl;
}

int main(void)
{
  int a[3] = { 2, 7, -1 };
  int b[6] = { 2, 7, -1, 0, 585, -68565 };

  show(1.0);
  show("hello");
  show(-3);
  show("John","name: ");
  show('a');
  show(a, 3);
  show(b, 6);
  return 0;
}
