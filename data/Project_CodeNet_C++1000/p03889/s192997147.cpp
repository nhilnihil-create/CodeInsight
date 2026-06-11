#include <iostream>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main(){
  string S,T;
  cin >> S;
  REP(i,(S.size())){
    if(S[i]=='b'&&S[S.size()-1-i]!='d'){
      cout << "No" << endl;
      return 0;
    }
    if(S[i]=='d'&&S[S.size()-1-i]!='b'){
      cout << "No" << endl;
      return 0;
    }
    if(S[i]=='p'&&S[S.size()-1-i]!='q'){
      cout << "No" << endl;
      return 0;
    }
    if(S[i]=='q'&&S[S.size()-1-i]!='p'){
      cout << "No" << endl;
      return 0;
    }
  }
  cout <<"Yes" << endl;
  return 0;
}
