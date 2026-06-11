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
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    set<double> water;
    set<double> sugar;
    rep(i, 31)rep(j, 31){
        if(100 * (i * a + j * b) <= f) water.insert(100 * (i * a + j * b));
    }
    rep(i, 3001)rep(j, 3001){
        if(i * c + j * d <= f) sugar.insert(i * c + j * d);
    }
    double max_dens = 0;
    int ans_w = 100 * a, ans_s = 0;
    for(double w : water){
        for(double s : sugar){
            if(w == 0) continue;
            if(w + s > f) continue;
            if(((100 * s) / (w + s)) > (100 * e / (100 + e))) continue;
            if(max_dens < ((100 * s) / (w + s))){
                max_dens = (100 * s) / (w + s);
                ans_w = w, ans_s = s;
            }
        }
    }
    cout << ans_s + ans_w << " " << ans_s << endl;
}