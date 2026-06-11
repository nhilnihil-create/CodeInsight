#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;
typedef pair<int,int> pr;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    ll n; cin >> n;
    string s; cin >> s;
    ll c1 = 0, c2 = 0;
    stack<char> m;

    rep(i,s.length()){
        if(!m.empty()){
            if(m.top() == '(' && s[i] == ')'){
                m.pop();
                continue;
            }
        }
        m.push(s[i]);
    }

    while(!m.empty()){
        if(m.top() == '(') c1 ++;
        else c2 ++;

        m.pop();
    }

    rep(i,c2) cout << '(';
    cout << s;
    rep(i,c1) cout << ')';


}