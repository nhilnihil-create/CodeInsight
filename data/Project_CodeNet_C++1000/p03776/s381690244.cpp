#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

ll com[51][51];

int main(){
    com[0][0] = 1;
    for(int i = 1; i < 51; ++i){
        for(int j = 0; j <= i; ++j){
            com[i][j] += com[i-1][j];
            if(j > 0) com[i][j] += com[i-1][j-1];
        }
    }
    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(RALL(v));
    ll sum = 0;
    rep(i,a) sum += v[i];
    double ave = double(sum)/a;
    ll res = 0;
    int num = 0;
    rep(i,n) if(v[i] == v[a-1]) ++num;
    if(v[0] == v[a-1]){
        for(int i = a; i <= b; i++) res += com[num][i];
    }else{
        int cnt = 0;
        for(int i = 0; i < a; ++i) if(v[i] == v[a-1]) cnt++;
        res = com[num][cnt];
    }
    cout << fixed << setprecision(15) << ave << endl;
    cout << res << endl;
}