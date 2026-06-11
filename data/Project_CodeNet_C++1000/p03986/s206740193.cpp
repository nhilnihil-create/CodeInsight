#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    string s; cin >> s;
    stack<char> st;

    rep(i,s.length()){
        if(st.empty()) st.push(s[i]);
        else if(st.top() == 'S' && s[i] == 'T'){
            st.pop();
        }else st.push(s[i]);
    }
    cout << st.size();

}