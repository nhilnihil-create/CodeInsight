#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
string s,t;
int q;
int sums[2][200000];
int sumt[2][200000];
signed main(){
  cin>>s>>t;
  cin>>q;
  rep(i,200000){
    sums[0][i]=0;
    sums[1][i]=0;
    sumt[0][i]=0;
    sumt[1][i]=0;
  }
  int sn=s.size();int tn=t.size();
  sums[s[0]-'A'][1]++;
  sumt[t[0]-'A'][1]++;
  rep1(i,sn){
    sums[0][i]=sums[0][i-1];
    sums[1][i]=sums[1][i-1];
    sums[s[i-1]-'A'][i]++;
  }
  rep1(i,tn){
    sumt[0][i]=sumt[0][i-1];
    sumt[1][i]=sumt[1][i-1];
    sumt[t[i-1]-'A'][i]++;
  }
  vector<int> res(q);
  rep(i,q){
    int a,b,c,d;cin>>a>>b>>c>>d;
    int k=sumt[0][d]-sumt[0][c-1]+1000000;
    int l=sumt[1][d]-sumt[1][c-1]+1000000;
    k-=sums[0][b]-sums[0][a-1];
    l-=sums[1][b]-sums[1][a-1];
    bool flag=false;
    if((2*k+l)%3==0&&(2*l+k)%3==0){
      flag=true;
    }
    	if(flag){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
  }
  return 0;
}
