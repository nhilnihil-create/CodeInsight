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
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  string s;cin>>s;
  int n=s.length();
  int rem=0;
  if(s[0]==s[n-1])++rem;
	if((n-rem)%2==1){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }
  return 0;
}