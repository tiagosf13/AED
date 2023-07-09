//
// Tomás Oliveira e Silva, AED, November 2021
//
// matched-parenthesis verification
//

#include <iostream>
#include "aStack.h"

using std::cout;
using std::cerr;
using std::endl;

int check_parenthesis(const char *s)
{
  aStack<char> stack;
  char c = '(';
  char d = ')';
  // put your code here (20 lines of code should be enough)
  for (int i = 0; s[i] != '\0'; i++){
    if (s[i] == '('){
      stack.push(c);
    }
    else if (s[i] == ')'){
      if (stack.is_empty() == 1){
        return -1;
      }
      else{
        stack.pop();
      }
    }
  }

  for (int i = 0; i <= stack.size(); i++){
    if (stack.is_empty() == 0){
      cout << "  unmatched '(' at position " << stack.size() << endl;
      stack.pop();
    }
  }

  return (stack.is_empty() == 1) ? 0 : -1;
}

int main(int argc,char **argv)
{
  if(argc == 1)
  {
    cerr << "usage: " << argv[0] << " [arguments...]" << endl;
    cerr << "example: " << argv[0] << " 'abc(def)ghi' 'x)(y'" << endl;
    return 1;
  }
  for(int i = 1;i < argc;i++)
  {
    cout << argv[i] << endl;
    if(check_parenthesis(argv[i]) == 0)
      cout << "  good" << endl;
    else
      cout << "  bad" << endl;
  }
  return 0;
}
