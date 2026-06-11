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
  vector<int>x(n);
  rep(i, n)cin>>x[i];

  map<int, int>mm,mp;
  rep(i,n){
    mp[x[i]%m]++;
    mm[x[i]]++;
  }

  int result=0;
  rep(i, m){
    if(i==0 || m%2==0 && i==m/2){
      result += mp[i]/2;
      continue;
    }
    int j=m-i;
    int ip=mp[i];
    int jp=mp[j];
    mp[i]=mp[j]=0;
    int many = i;
    if(jp > ip){
      many=j;
      swap(ip, jp);
    }
    result += jp;
    ip -= jp, jp=0;
    for(int k=many; k<=MAXM; k+=m){
      int d = min(ip/2 , mm[k]/2);
      if(d){
        result += d;
        ip -= d*2;
      }
    }
  }

  cout<<result<<endl;

  return 0;
}