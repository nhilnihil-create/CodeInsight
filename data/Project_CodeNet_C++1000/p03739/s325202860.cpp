#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976
const double PI = 3.1415926535897932;

int main()
{
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll sum = 0,ans1 = 0,ans2 = 0;
    rep(i,n){
        sum += a[i];
        if(i % 2 == 0 && sum <= 0){
            ans1 += 1-sum;
            sum = 1;
        }
        if(i % 2 == 1 && sum >= 0){
            ans1 += sum+1;
            sum = -1;
        }
    }
    sum = 0;
    rep(i,n){
        sum += a[i];
        if(i % 2 == 1 && sum <= 0){
            ans2 += 1-sum;
            sum = 1;
        }
        if(i % 2 == 0 && sum >= 0){
            ans2 += sum+1;
            sum = -1;
        }
    }
    cout << min(ans1,ans2);
}