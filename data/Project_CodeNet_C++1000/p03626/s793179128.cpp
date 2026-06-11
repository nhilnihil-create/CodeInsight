#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define Rep(i, r, n) for (ll i = r; i < n; i++)
#define debug(x) cout << #x << " = " << (x) << endl;
#define MOD 1000000007
//#define MOD 998244353
#define EPS (1 >> 30)
//#define INF (1 << 30)
#define INF (1LL << 60)
#define fs first
#define sc second
//#define int long long
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

using Graph = vector<vector<pair<int, int>>>;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    //---------------------------------------------

    int joutai; // tate 0 yoko 1
    int n;
    string s,t;
    cin>>n>>s>>t;
    ll ans=0;
    if(s[0]==t[0]){ // tate 0
        joutai=0;
        ans=3;
        //cout<<ans<<endl;
    }
    else{ // yoko 1
        joutai=1;
        ans=6;

    }

    for(int i=0;i<n;i++){
        if(i==0){
            if(joutai==0){
                continue;
            }
            else{
                i++;
                continue;
            }
        }
        int mae=joutai;
        if(s[i]==t[i]){
            joutai=0;
        }
        else{
            joutai=1;
        }

        if(mae==0&&joutai==0){
            ans*=2;
            ans%=MOD;
        }
        else if(mae==0&&joutai==1){
            ans*=2;
            ans%=MOD;
            i++;
        }
        else if(mae==1&&joutai==0){
            ans*=1;
            ans%=MOD;
        }
        else if(mae==1&&joutai==1){
            ans*=3;
            ans%=MOD;
            i++;
        }
    }
    cout<<ans<<endl;

}
