#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int main()
{
    string x;
    cin >> x;
    int ans=x.size();
    int s=0;
    int t=0;
    bool b=true;
    REP(i,x.size()){
        if(b&&x[i]=='S'){
            ans-=min(s,t)*2;
            b=false;
            if(s>t){
                s-=t-1;
                t=0;
            }
            else{
                s=1;
                t=0;
            }
        }
        else if(x[i]=='S'){
            s++;
        }
        else{
            b=true;
            t++;
        }
    }
    ans-=min(s,t)*2;
    cout << ans << endl;
}
