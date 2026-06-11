#include <bits/stdc++.h>
#include <map> // pair
using namespace std;

typedef long long ll;
#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define llrep(i,n)   for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prt_dbl(i,var) cout<<fixed<<setprecision(i)<<var<<endl;
template <typename T>
T gcd(T a, T b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
//use ll or int for gcd

//---------------------------------------------------------------

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  ll Amax = 0;
  rep(i,N){
    cin>>A.at(i);
    Amax = max(Amax,A.at(i));
  }
  sort(A.begin(),A.end(),greater<ll>());

  vector<pair<int,ll>>T;
  int count = 1;
  rep(i,N){
//    cout<<A.at(i)<<" "<<count<<endl;
    if(i<N-1){
      if(A.at(i)==A.at(i+1))count++;
      else{
        if(count>1)T.push_back(make_pair(count,A.at(i)));
        count = 1;
      }
    }else{
      if(count>1)T.push_back(make_pair(count,A.at(i)));
      count = 1;
    }
  }
  ll ans;
  if(T.size()<2){
    ans = 0;
  }else if(T.size()==1&&T.at(0).first<4){
    ans = 0;
  }else if(T.at(0).first>3){
    ans = T.at(0).second*T.at(0).second;
  }else{
    ans = T.at(0).second*T.at(1).second;
  }
//  cout<<T.size()<<endl;;
  cout<<ans<<endl;
}
