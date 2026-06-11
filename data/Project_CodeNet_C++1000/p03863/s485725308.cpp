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
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  int n=len(s);
  if(s[0]==s[n-1]){
    if(n%2==0) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
  }else{
    if(n%2==1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
  }
}