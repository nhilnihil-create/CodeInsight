#include "bits/stdc++.h"
#define all(v) v.begin(),v.end()
#define SZ(x) (int)x.size()
#define endl "\n"
#define thunder ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(15);
using namespace std;
typedef long long int ll;
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
void debug_out() { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
int main()
{
    thunder
    auto start = chrono::high_resolution_clock::now();
    int n,t;cin>>n>>t;
    vector<ll>v(n+1);
    for(auto &x:v)cin>>x;
    v[n]=INT_MAX;
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        if(v[i+1]-v[i]>=t)
        {
            ans+=ll(t);
        }
        else
        {
            ans+=ll(v[i+1]-v[i]);
        }
    }
    cout<<ans<<endl;
   
   





   auto end = chrono::high_resolution_clock::now(); 
   double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
   time_taken *= 1e-9;
   debug(time_taken);
}