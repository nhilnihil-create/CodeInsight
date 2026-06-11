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
map<int,ll>mp;
int main()
{
    thunder
    auto start = chrono::high_resolution_clock::now();
    int n;ll k;cin>>n>>k;
    for(int i=0,x,y;i<n;++i)
    {
        cin>>x>>y;
        mp[x]+=y;
    }
    for(auto x:mp)
    {
        debug(x.first,x.second);
        if(x.second<k)k-=x.second;
        else
        {
           cout<<x.first<<endl;return 0;
        }
    }

   





   auto end = chrono::high_resolution_clock::now(); 
   double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
   time_taken *= 1e-9;
   debug(time_taken);
}