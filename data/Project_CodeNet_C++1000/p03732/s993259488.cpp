#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 109, M = 509, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int n, cap, f; cin >> n >> cap;

    vector<int> v[4];
    for(int i = 0;i < 4;i++)    v[i].push_back(0);

    for(int i = 0;i < n;i++){
        int w, val;   cin >> w >> val;
        if(!i)  f = w;
        v[w - f].push_back(val);
    }

    for(int i = 0;i < 4;i++)    sort(v[i].rbegin(), v[i].rend() - 1);
    for(int i = 0;i < 4;i++)    partial_sum(v[i].begin(), v[i].end(), v[i].begin());

    ll ans = 0;
    for(int i = 0;i < v[0].size();i++){
        for(int j = 0;j < v[1].size();j++){
            for(int k = 0;k < v[2].size();k++){
                for(int l = 0;l < v[3].size();l++){
                    ll vals = v[0][i] + v[1][j] + v[2][k] + v[3][l];
                    ll w = (ll)f * (i + j + k + l) + j + 2 * k + 3 * l;
                    if(w <= cap)    ans = max(ans, vals);
                }
            }
        }
    }

    cout << ans;
}