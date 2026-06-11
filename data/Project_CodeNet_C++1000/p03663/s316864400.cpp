#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/
 
 
typedef long long ll;
ll hint = 10;
int get(ll n) {
    if (n == 0) return 0;
 
    printf("? %lld\n", n);

    fflush(stdout);
    string s; cin >> s;
    if (s == "Y") return 1;
    else return 0;
}
//---------------------------------------------------------------------------------------------------
ll str2int(string s) {
    ll res = 0;
    fore(i, s) res = res * 10 + i - '0';
    return res;
}
//---------------------------------------------------------------------------------------------------
int findDigit() {
    int ng = 1, ok = 19;
    while (ng + 1 != ok) {
        int x = (ng + ok) / 2;
        string s = "1";
        rep(i, 0, x - 1) s += "0";
        if (!get(str2int(s))) ok = x;
        else ng = x;
    }
    int dig = ok - 1;

    if (dig == 18) {
        ng = 0, ok = 11;
        while (ng + 1 != ok) {
            int x = (ng + ok) / 2;
            string s = "9";
            rep(i, 0, x - 1) s += "9";
            if (get(str2int(s))) ok = x;
            else ng = x;
        }
        dig = ok;
    }

    return dig;
}
//---------------------------------------------------------------------------------------------------
ll solve() {
    int dig = findDigit();
 
    string ans = "";
    rep(i, 0, dig - 1) {
        int ok = 0, ng = 10;
        while (ok + 1 != ng) {
            int x = (ok + ng) / 2;
            string a = ans + char('0' + x);
            if (get(str2int(a))) ok = x;
            else ng = x;
        }
        ans += char('0' + ok);
    }
 
    int ng = -1, ok = 10;
    while (ng + 1 != ok) {
        int x = (ok + ng) / 2;
        string a = ans + char('0' + x) + "0";
        if (get(str2int(a))) ok = x;
        else ng = x;
    }
    ans += char('0' + ok);
 
    return str2int(ans);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    ll a = solve();
    printf("! %lld\n", a);
}