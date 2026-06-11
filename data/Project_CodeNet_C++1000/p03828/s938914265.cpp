#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9+7;

int main(){
    int n; cin >> n;
    map<int, int> ma;
    for(int i = 1; i <= n; ++i){
        int t = i;
        for(int j = 2; j * j <= t; ++j){
            int cnt = 0;
            while(t % j == 0){
                t/=j;
                cnt++;
            }
            ma[j] += cnt;
        }
        if(t != 1) ma[t]++;
    }
    ll ans = 1;
    for(auto e : ma){
        //int p = e.first;
        int q = e.second;
        //cout << p << " " << q << endl;
        ans *= (q+1);
        ans %= mod;
    }
    cout << ans << endl;
}