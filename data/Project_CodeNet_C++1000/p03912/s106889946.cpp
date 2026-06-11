#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXM 110000

int main(){
  int n,m;cin>>n>>m;
  vector<int> x(n);
  rep(i, n)cin>>x[i];
  map<int, int>mp, mm;
  rep(i, n){
    mm[x[i]]++;
    mp[x[i]%m]++;
  }

  int result = 0;
  int tr = 0;
  rep(i, m){
    if(i==0 || m%2==0 && i==m/2){
      tr += mp[i]/2;
    }else{
      int j = m-i;
      int s=mp[i],t=mp[j];
      mp[i]=0,mp[j]=0;
      if(s>t){
        swap(s,t);
        j=i;
      }
      //if(s==0)continue;
      result += s;
      t-=s;s=0;

      for(int k=j; k<=MAXM; k+=m){
        if(t>=2 && mm[k]>=2){
          int x = min(mm[k]/2, t/2);
          result += x;
          t -= 2*x;
        }
      }
    }
  }

  cout<<result+tr<<endl;
//  cout<<result<<' '<<tr<<endl;

  return 0;
}
