#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  string o,e;
  cin>>o>>e;

  rep(i,o.length()+e.length()){
    if(i%2==0){
      cout<<o[i/2];
    }else{
      cout<<e[i/2];
    }
  }

  cout<<endl;
  return 0;
}
