#include<iostream>
using namespace std;
int main()
{
  int a,b;
  char op;
  cin>>a>>op>>b;
  int result;
  switch (op) {
    case '+' : result = a + b;break;
    case '-' : result = a - b;break;
  }
  cout << result;

  return 0;
}
