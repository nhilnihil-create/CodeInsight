#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end() 
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){
    speed;
    int n; cin >> n;
    stack<char> st;
    string s; cin >> s;
    rep(i, 0, s.size()) {
        char c; c = s[i];
        if(st.empty()) {
            st.push(c);
        } else {
            if(st.top() != c && st.top() == '(') {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    while(!st.empty()) {
        if(st.top() == '(') cnt2++;
        else cnt1++;
        st.pop();
    }
    rep(i, 0, cnt1) cout << '(';
    cout << s;
    rep(i, 0, cnt2) cout << ')';
    return 0;
}