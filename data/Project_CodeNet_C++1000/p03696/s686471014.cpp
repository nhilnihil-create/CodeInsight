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


int main()
{
    int n; cin >> n;
    string s; cin >> s;

    int score = 0;
    int score_min = 0;
    rep(i, n){
        if (s[i] == '('){
            score++;
        } else {
            score--;
        }
        score_min = min(score, score_min);
    }
    int l = -score_min;
    int r = score - score_min;
    string ans = "";
    rep(i, l) ans += "(";
    ans += s;
    rep(i, r) ans += ")";
    
    cout << ans << endl;
}

