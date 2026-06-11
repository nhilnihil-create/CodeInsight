#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {

    string s; cin >> s;
    stack<char> t,m;
    rep(i,s.length()){
        if(s[i] == 'B'){
            if(!t.empty()) t.pop();
        }else t.push(s[i]);
    }

    while(!t.empty()){
        m.push(t.top());
        t.pop();
    }

    while(!m.empty()) {
        cout << m.top();
        m.pop();
    }
    return 0;
}









