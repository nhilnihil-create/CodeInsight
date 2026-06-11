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
    string s;
    ll K;
    cin >> s >> K;
    ll N = s.size();
    rep(i, 0, N-1){
        ll t = s[i] - 'a';
        if(t == 0) continue;
        if(26 - t <= K){
            K -= (26 - t);
            s[i] = 'a';
        }
    }
    K %= 26;
    if(s[N-1] + K > 'z') s[N-1] = 'a' + K - ('z' + 1 - s[N-1]);
    else s[N-1] += K; 
    cout << s << endl;
    return 0;
}