#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
#define ld long double
int inf=100000000;
ll INF=4000000000000000000;
ll MOD=1000000007;



int main() {
   int n,t;
   cin >> n >> t;
   ll a;
   ll mi=INF,no,b=0,ans=0;
   rep(i,n){
     cin >> a;
     if (b==a-mi && no!=mi) ans++;
     if (b<a-mi) {
       no=mi;
       ans=1;
       b=a-mi;
     }
     if (a<mi) {mi=a;}
   }
  cout << ans << endl;
}
