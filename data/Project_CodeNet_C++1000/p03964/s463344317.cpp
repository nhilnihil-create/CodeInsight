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
int main(){
    int n; cin >> n;
    ll x = 1, y = 1; 
    rep(i, n){
        ll a, b; cin >> a >> b;
        ll MAX = max((a + x - 1) / a, (b + y - 1) / b);
        x = MAX * a;
        y = MAX * b;
        //cout << x << " " << y << endl;
    }
    cout << x + y << endl;
}