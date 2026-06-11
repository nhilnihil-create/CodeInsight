#include <iostream>

int main()
{
  int N;
  std::string S;
  std::cin >> N >> S;
  int stack = 0; // number of "(" char in stack

  std::string ret = "";
  int i = 0;
  while(i < N) {
    switch(S[i]) {
      case '(': {
        if(i+1 < N && S[i+1] == ')') {
          ret += "()";
          i++; // skip 2, 1 more ++ in the end of while
        } else {
          ret += "(";
          stack++;
        }
        break;
      }
      case ')': {
        if(stack > 0) {
          ret += ")";
          stack--;
        } else {
          ret = "(" + ret + ")";
        }
        break;
      }
      default:
        // never come here
        break;
    }
    // std::cout << ret << " " << stack << std::endl;
    i++;
  }

  for(i=0; i<stack; i++) {
    ret += ")";
  }

  std::cout << ret << std::endl;
  return 0;
}
