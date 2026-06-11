#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;
    cin>>n>>x;
    if(x==1||x==2*n-1) cout<<"No"<<endl;
    else{
      cout<<"Yes"<<endl;
      if(n==2) FOR(i,1,2*n) cout<<i<<endl;
      else{
        vector<ll> cnt;
        if(x==2){
          cnt.push_back(-1);
          FOR(i,1,2*n){
            if(i!=x-1 && i!=x && i!=x+1 && i!=x+2) cnt.push_back(i);
          }
          FOR(i,1,n-1) cout<<cnt[i]<<endl;
          cout<<x-1<<endl;
          cout<<x<<endl;
          cout<<x+1<<endl;
          cout<<x+2<<endl;
          FOR(i,n-1,len(cnt)) cout<<cnt[i]<<endl;
        }else{
          cnt.push_back(-1);
          FOR(i,1,2*n){
            if(i!=x-1 && i!=x && i!=x+1 && i!=x-2) cnt.push_back(i);
          }
          FOR(i,1,n-1) cout<<cnt[i]<<endl;
          cout<<x-1<<endl;
          cout<<x<<endl;
          cout<<x+1<<endl;
          cout<<x-2<<endl;
          FOR(i,n-1,len(cnt)) cout<<cnt[i]<<endl;
          //cout_vec(cnt);
        }
      }
    }
}