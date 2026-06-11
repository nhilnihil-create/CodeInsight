#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
 
/*------------------------------------------------------------------*/
 
int main(){
    vector<long double> a(4);
    rep(i, 4) cin >> a[i];
    long double n; cin >> n;
    vector<pair<long double, long double>> b(4);
    b[0].first = 8 * a[0], b[0].second = 0.25;
    b[1].first = 4 * a[1], b[1].second = 0.5;
    b[2].first = 2 * a[2], b[2].second = 1.0;
    b[3].first = a[3], b[3].second = 2.0;
    sort(b.begin(), b.end());

    long double sum = 0;
    for(int i = 0; i < 4; i++){
        sum += (ll)(n / b[i].second) * (b[i].first * b[i].second) / 2;
        n -= (ll)(n / b[i].second) * b[i].second;
        //cout << sum << " " << n << endl;
    }
    cout << setprecision(20) << sum << endl;
}
