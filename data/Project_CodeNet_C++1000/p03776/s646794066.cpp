#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
ll com[55][55];

int main(){
    int n,a,b; cin >> n >> a >> b;
    rep(i, 55){
        rep(j, i+1){
            if(i == 0 || j == i) com[i][j] = 1LL;
            else com[i][j] = com[i-1][j-1] + com[i-1][j];
        }
    }
    double amax = 0;
    ll cnt = 0;
    vector<double> v(n);
    rep(i,n) cin >> v[i];
    sort(RALL(v));
    double sum = 0.0;
    rep(i,a) sum += v[i];
    amax = sum / (double)a;
    int var = 0, num = 0;
    rep(i,a) if(v[i] == v[a-1]) var++;
    rep(i,n) if(v[i] == v[a-1]) num++;
    cnt = com[num][var];
    if(v[0] == v[a-1]){
        cnt = 0;
        FOR(i,a,b+1) cnt += com[num][i];
    }
    cout << setprecision(10);
    cout <<  fixed << amax << endl;
    cout << cnt << endl;
}
