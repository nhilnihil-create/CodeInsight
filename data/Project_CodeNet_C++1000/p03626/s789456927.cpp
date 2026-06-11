#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1;
    cin >> s2;
    int now, pre;
    ll ans;
    if(s1[0] == s2[0]){
        ans = 3;
        now = 1;
        pre = 1;
    }else{
        ans = 6;
        now = 2;
        pre = 2;
    }
    while(now < n){
        if(s1[now] == s2[now]){
            if(pre == 1){
                ans *= 2;
            }
            now += 1;
            pre = 1;
        }else{
            if(pre == 1){
                ans *= 2;
            }else{
                ans *= 3;
            }
            now += 2;
            pre = 2;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}