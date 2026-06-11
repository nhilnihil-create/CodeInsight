#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int N,A,B;
  string S;

  cin >> N >> A >> B;
  cin >> S;

  int pass=0;
  int sumb=0;

  
  for (int i = 0; i < N; i++)
  {
    if(S[i]=='a'){
      if(pass<A+B){
        pass++;
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else if(S[i]=='b'){
      if(pass<A+B && sumb<B){
        pass++;
        sumb++;
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else{
      cout << "No" << endl;
    }
  }
  
  return 0;
}