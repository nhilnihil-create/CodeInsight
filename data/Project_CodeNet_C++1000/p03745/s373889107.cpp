#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n){
        cin >> v[i];
    }
    int cnt = 1;
    int pre = 0;
    bool init = 1;
    rep(i,n){
        if(i == 0) continue;
        if(v[i-1] < v[i]){
            if(pre == 0 && !init){
                cnt++;
                init = 1;
            }else if(init){
                pre = 1;
                init = 0;
            }
        }else if(v[i-1] > v[i]){
            if(pre == 1 && !init){
                cnt++;
                init = 1;
            }else if(init){
                pre = 0;
                init = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}