#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(x) x.begin(),x.end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }

int n;
vector<int>p;
ll solve(){
   ll ans=0;
   rep(i,n){
       if(i==p[i]){
           ans++;
           if(i<n-1)
           swap(p[i],p[i+1]);
       }
   }

   return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    p.resize(n);
    rep(i,n){
        cin>>p[i];
        p[i]--;
    }
    cout<<solve()<<endl;
    return 0;
}