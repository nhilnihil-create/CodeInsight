#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


/*
[check]条件の見逃し
最終系はTTTSSSになる
STTSTTS => TTS
何回消去が起きるか
TSSSTTS
T{ST}T
*/

int main()
{
    string s;
    cin >> s;
    int tmp = 0;
    int cnt_s = 0;
    int cnt_t = 0;
    int ans = 0;
    rep(i, s.size()){
        if (s[i] == 'S'){
            cnt_s++;            
        } else {
            if (cnt_s > 0){
                ans++;
                cnt_s--;
            }
        }
    }
    ans = s.size() - ans*2;
    cout << ans << endl;
}

