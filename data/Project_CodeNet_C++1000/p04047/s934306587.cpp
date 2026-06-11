/*
 *  ॐॐॐॐ
 *  मनुष्य के साहस से बड़ा कोई लक्ष्य नहीं, हारा वही जो लड़ा नहीं ।। 
 *          ---- स्वामी विवेकानंद जी
 */
/*
 * Author: @SumitRaut
 */


#include <bits/stdc++.h>
#define debug1(x) cerr<<#x<<' '<<x<<'\n'
#define debug2(x,y) cerr<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n'
#define debug3(x,y,z) cerr<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n'
#define sbc __builtin_popcount
#define pb push_back
#define em emplace
#define emb emplace_back
#define ll long long
int mod = 1e9+7;

template<typename T> void smax(T& a, T b) { if(a<b) a=b; }
template<typename T> void smin(T& a, T b) { if(a<b) a=b; }
template<typename T> T pw(T a,T b) { T p=1,one=1; while(b) { if(b&one) p=p*a; a=a*a; b >>=1; } return p; }
template<typename T> T gcd(T x,T y) { /* if(y==0) return x; return gcd (y,x%y); */ T t; while(y!=0) { t=y; y=x%y; x=t; } return x; }
template<typename T> T pwm(T a,T b) { T p=1,one=1,md=1e9+7; while(b) { if(b&one) p=p*a%md; a=a*a%md; b >>=1; } return p; }

using namespace std;
struct Timer { chrono::high_resolution_clock::time_point start_t, end_t; Timer() { start_t=chrono::high_resolution_clock::now(); } ~Timer() { end_t = chrono::high_resolution_clock::now(); auto duration = chrono::duration_cast<chrono::milliseconds>(end_t-start_t); cerr<<"\nRunTime: "<<duration.count()<<"ms"<<'\n'; } };

inline void solve() {
    // Timer timer;
 int n;
 cin>>n;
 n*=2;
 int arr[n],i=-1,ans=0;
 while(++i<n) cin>>arr[i];
 sort(arr,arr+n);
 i=0;
 while(i<n) ans+=arr[i],i+=2;
 cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; cin>>t; while(t--)
        solve();
    return 0;
}

