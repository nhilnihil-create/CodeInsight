#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll n,x=0,max=0;
  string s;
  cin>>n>>s;

  rep(i,s.length()){
    s[i]=='I'?x++:x--;
    if(x>max)max=x;
  }

  cout<<max<<endl;
return 0;
}
