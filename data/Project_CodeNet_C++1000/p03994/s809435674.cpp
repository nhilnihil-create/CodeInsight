#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

/*
[check]
辞書順最小

前から評価する。
azzzzz 26
の場合、aで26を浪費しないように！

*/

int main()
{
    string s;
    int n;
    cin >> s;
    cin >> n;

    rep(i, s.size()){
        if (s[i] == 'a') continue;
        int c = 'z'-s[i];
        if (c < n){
            s[i] = 'a';
            n -= c+1;
        }
    }
    if (n != 0){
        int c = s[s.size()-1]-'a';
        int alpha_num = 'z'-'a'+1;
        c = (c+n)%alpha_num;
        //cout << c << endl;
        s[s.size()-1] = c + 'a';
    }

    cout << s << endl;
}

