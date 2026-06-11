#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < n; i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(st.top() == '('){
            if(s[i] == '(') st.push(s[i]);
            else st.pop();
        }else{
            st.push(s[i]);
        }
    }
    int left = 0;
    int right = 0;
    while(!st.empty()){
        char c = st.top();
        st.pop();
        if(c == '(')right++;
        else left++;
    }
    string ans = "";
    rep(i,left) ans += '(';
    ans += s;
    rep(j,right) ans += ')';
    cout << ans << endl;
}