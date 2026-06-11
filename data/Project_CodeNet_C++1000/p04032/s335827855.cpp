#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  string s;
  cin>>s;

  char pre='*',prepre='*';
  rep(i,s.size()){
    if(s[i]==pre){
      cout<<i<<' '<<i+1<<endl;
      return 0;
    }
    if(s[i]==prepre){
      cout<<i-1<<' '<<i+1<<endl;
      return 0;
    }
    prepre=pre;
    pre=s[i];
  }
  cout<<-1<<' '<<-1<<endl;
  return 0;
}
