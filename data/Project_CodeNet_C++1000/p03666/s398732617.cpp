#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
//const int inf=1000000007;
const int MOD=1000000007;
int n,a,b,c,d;
signed main(){
  cin>>n>>a>>b>>c>>d;
  bool flag=false;
  for(int i=n-1;i>=0;--i){
    int sup=d*i-c*(n-i-1);
    int inf=c*i-d*(n-i-1);
    if(b-a>=inf&&b-a<=sup){
      //cout<<i<<"\n";
      flag=true;
      break;
    }
  }
  	if(flag){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  return 0;
}
