#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
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

/*------------------------------------------------------------------*/
int main(){
    ll h, w; cin >> h >> w;

    ll s1, s2, s3;
    ll s_abs;
    ll diff_min = 1e11;
    for(int i = 1; i < w; i++){
        s1 = h * i;
        s2 = h * ((w - i) / 2);
        s3 = h * ((w - i) - (w - i) / 2);
        diff_min = min(max({s1, s2, s3}) - min({s1, s2, s3}), diff_min);
    }
    for(int i = 1; i < h; i++){
        s1 = w * i;
        s2 = w * ((h - i) / 2);
        s3 = w * ((h - i) - (h - i) / 2);
        diff_min = min(max({s1, s2, s3}) - min({s1, s2, s3}), diff_min);
    }
    for(int i = 1; i < w; i++){
        s1 = h * i;
        s2 = h / 2 * (w - i);
        s3 = (h - h / 2) * (w - i);
        diff_min = min(max({s1, s2, s3}) - min({s1, s2, s3}), diff_min);
    }
    for(int i = 1; i < h; i++){
        s1 = w * i;
        s2 = w / 2 * (h - i);
        s3 = (w - w / 2) * (h - i);
        diff_min = min(max({s1, s2, s3}) - min({s1, s2, s3}), diff_min);
    }
    cout << diff_min << endl;
}