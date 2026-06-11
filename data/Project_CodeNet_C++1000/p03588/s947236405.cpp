#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
   cin.tie(0);
   ios::sync_with_stdio(false);
   cout<<fixed<<setprecision(20);

   int N;
   cin >> N;
   map<int,int> mp;
   int mn = inf;
   int mx = 0;
   rep(i,N){
      int a,b;
      cin >> a >> b;
      mp[a] = b;
      mn = min(mn,a);
      mx = max(mx,a);
   }
   // for(auto x:mp)cout << x.first << endl;
   cout << mx + mp[mx]<< endl;
}