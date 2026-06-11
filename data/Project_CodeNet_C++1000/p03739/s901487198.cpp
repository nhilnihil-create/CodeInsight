#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;
/*------------------------------------------------------------------*/
int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll sum1 = 0, sum2 = 0;
    ll ans1 = 0, ans2 = 0;

    rep(i, n){
        if(sum1 + a[i] > 0){
            if(i % 2 == 0) sum1 += a[i];
            else{
                ans1 += 1 + (sum1 + a[i]);
                sum1 = -1;
            }
        }else if(sum1 + a[i] == 0){
            if(i % 2 == 0) sum1 = 1;
            else sum1 = -1;
            ans1++;
        }else{
            if(i % 2 == 0){
                ans1 += 1 + abs(sum1 + a[i]);
                sum1 = 1;
            }else sum1 += a[i];
        }
    }
    rep(i, n){
        if(sum2 + a[i] > 0){
            if(i % 2 == 1) sum2 += a[i];
            else{
                ans2 += 1 + (sum2 + a[i]);
                sum2 = -1;
            }
        }else if(sum2 + a[i] == 0){
            if(i % 2 != 0) sum2 = 1;
            else sum2 = -1;
            ans2++;
        }else{
            if(i % 2 == 1){
                ans2 += 1 + abs(sum2 + a[i]);
                sum2 = 1;
            }else sum2 += a[i];
        }
    }
    cout << min(ans1, ans2) << endl;
}