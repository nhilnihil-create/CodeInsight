#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
using ull = unsigned long long int;
using P = pair<int, int>;
using P3 = pair<ll,P>;
using PP = pair<P ,P>;
constexpr ll MOD = 998244353;
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e6) + 5;
constexpr double EPS = 1e-8;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

int main(){
    ll H, W, h, w, X = 1e8;
    cin >> H >> W >> h >> w;
    vector<vector<ll> > ans(H, vector<ll>(W, 1));
    for(int i=h-1;i<H;i+=h){
        for(int j=w-1;j<W;j+=w){
            ans[i][j] = -h*w-X;
        }
    }
    for(int i=0;i<H;i+=h){
        for(int j=0;j<W;j+=w){
            ans[i][j] += X;
        }
    }
    ll sum = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            sum += ans[i][j];
        }
    }
    if(sum > 0){
        cout << "Yes" << endl;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cout << ans[i][j] << " \n"[j==W-1];
            }
        }
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}