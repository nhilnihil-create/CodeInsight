#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    set<ll> x, y;
    for(ll a = 0; a <= F; a += 100 * A){
        for(ll b = 0; b <= F - a; b += 100 * B){
            x.insert(a + b);
        } 
    }
    for(ll c = 0; c <= F; c += C){
        for(ll d = 0; d <= F - c; d += D){
            y.insert(c + d);
        } 
    }
    ll ansF = 100*A, ansS = 0;
    double node = 0;
    for(auto w : x){
        for(auto s : y){
            if(w + s <= F && s <= E * w / 100){
                if(node < 100 * (double) s / (double)(s + w)){
                    ansF = s + w;
                    ansS = s;
                    node = 100 * (double) s / (double)(s + w);
                }
            }
        }
    }
    cout << ansF << " " << ansS << endl;
    return 0;
}