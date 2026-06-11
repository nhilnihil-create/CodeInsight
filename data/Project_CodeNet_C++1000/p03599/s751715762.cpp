#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<int>water, suger;
    for(int i=0; i*100*a<=f; i++){
        for(int j=0; i*a*100+j*b*100<=f; j++){
            if(i==0&&j==0)continue;
            water.push_back(i*a*100+j*b*100);
        }
    }
    for(int i=0; i*c<=f; i++){
        for(int j=0; i*c+j*d<=f; j++){
            suger.push_back(i*c+j*d);
        }
    }
    water.erase(unique(water.begin(),water.end()),water.end());
    suger.erase(unique(suger.begin(),suger.end()),suger.end());
    int n = water.size();
    int m = suger.size();
    double ans = 0;
    int res1 = 100*a, res2 = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            if(water[i]+suger[j]>f)continue;
            double temp = ans;
            if(suger[j]<=water[i]/100*e){
                temp = (double)(100*suger[j])/(suger[j]+water[i]);
                if(temp>ans){
                    res1 = suger[j]+water[i];
                    res2 = suger[j];
                    ans = temp;
                }
            }
        }
    }
    cout << res1 << " " << res2 << endl;
}