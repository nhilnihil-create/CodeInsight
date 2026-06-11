#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i< (int)(b); ++i)
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
typedef long double ld;
using ll=long long;
using namespace std;
const int mod=1e9+7;
const ld pi = (acos(-1));
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  
   int n,m,k; cin >> n >> m >> k;
   rep(j,0,n+1) {
     rep(i,0,m+1) {
       int res=i*(n-j)+j*(m-i);
       if(res==k){
          cout << "Yes" << endl;
          return 0;
       }
     }
   } 
   cout << "No" << endl;
}