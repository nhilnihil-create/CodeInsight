#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  string s; cin >> s;
  int k; cin >> k;
  int n=s.size();
  rep(i,n){
    if(s[i]!='a'&&k>='{'-s[i]){
      k-='{'-s[i];
      s[i]='a';
    }
  }
  if(k>0){
    s[n-1]=char('a'+(s[n-1]-'a'+k)%26);
  }
  cout << s << endl;  
}