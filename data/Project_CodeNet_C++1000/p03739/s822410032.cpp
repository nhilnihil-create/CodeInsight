#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<ll, ll>;
using P3 = pair<P,int>;
using PP = pair<P, P>;
constexpr ll INF = 1LL << 60;
constexpr ll MOD = ll(1e9)+7;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};
constexpr int di8[] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr int dj8[] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr double EPS = 1e-9;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll ans1 = 0, ans2 = 0;
    ll s = 0;
    for(int i=0;i<n;i++){
        s += a[i];
        if(i%2){
            if(s <= 0){
                ans1 += abs(s)+1;
                s = 1;
            }
        }else{
            if(s >= 0){
                ans1 += abs(s)+1;
                s = -1;
            }
        }
    }
    s = 0;
    for(int i=0;i<n;i++){
        s += a[i];
        if(i%2){
            if(s >= 0){
                ans2 += abs(s)+1;
                s = -1;
            }
        }else{
            if(s <= 0){
                ans2 += abs(s)+1;
                s = 1;
            }
        }
    }
    cout << min(ans1,ans2) << endl;
    return 0;
}
