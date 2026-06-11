#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  string S;
  cin >> S;
  int flag=0;
  while(S!=""){
    int N = S.size();
    if(N>=7){
      if(S.substr(N-7,7)=="dreamer"){
        S=S.substr(0,N-7);
      }else if(S.substr(N-6,6)=="eraser"){
        S=S.substr(0,N-6);
      }else if(S.substr(N-5,5)=="erase"){
        S=S.substr(0,N-5);
      }else if(S.substr(N-5,5)=="dream"){
        S=S.substr(0,N-5);
      }else{
        flag=1;
        break;
      }
    }else if(N==6){
      if(S.substr(N-6,6)=="eraser"){
        S=S.substr(0,N-6);
      }else if(S.substr(N-5,5)=="erase"){
        S=S.substr(0,N-5);
      }else if(S.substr(N-5,5)=="dream"){
        S=S.substr(0,N-5);
      }else{
        flag=1;
        break;
      }
    }else if(N==5){
      if(S.substr(N-5,5)=="erase"){
        S=S.substr(0,N-5);
      }else if(S.substr(N-5,5)=="dream"){
        S=S.substr(0,N-5);
      }else{
        flag=1;
        break;
      }
    }else{
      flag=1;
      break;
    }
  }

  if(flag==1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}