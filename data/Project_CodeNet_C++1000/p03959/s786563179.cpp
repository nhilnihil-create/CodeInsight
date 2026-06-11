#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define Rep(i, r, n) for (ll i = r; i < n; i++)
#define RRep(i, r, n) for (ll i = n - 1; i <= r; i--)
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define int long long
#define pb push_back
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int MOD = (1000000007);
//const int MOD = (998244353);
//const int INF = (1 << 30)-1;
const int INF = (1LL << 60)-1;
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}

using Graph = vector<vector<pair<int, int>>>;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    //---------------------------------------------
    
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    vector<int> aa(n);
    vector<int> bb(n);
    vector<int> cc(n,1);
    if(n==1&&b[0]==a[0]){cout<<1<<endl;}
    else if(n==1){cout<<0<<endl;}
    else{
        aa[0]=1;
        bb[n-1]=1;
        Rep(i,1,n){
            if(a[i-1]<a[i]) aa[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(b[i]>b[i+1]) bb[i]=1;
        }
        int dame=0;
        ll ans=1;
        rep(i,n){
            if(aa[i]==1&&bb[i]==1){
                if(a[i]!=b[i]) dame++;
            }
            else if(aa[i]==bb[i]){
                cc[i]=min(a[i],b[i]);
            }
            else{
                if(aa[i]==1){
                    if(a[i]<=b[i]){
                        cc[i]=1;
                    }
                    else{
                        dame++;
                    }
                }
                if(bb[i]==1){
                    if(b[i]<=a[i]){
                        cc[i]=1;
                    }
                    else{
                        dame++;
                    }
                }
            }
            ans*=cc[i];
            ans%=MOD;
            //cout<<aa[i]<<" "<<bb[i]<<" "<<cc[i]<<endl;
        }
        if(dame==0){
            cout<<ans<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}