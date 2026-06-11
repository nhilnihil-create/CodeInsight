#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {

    string s; cin >> s;
    char c = 'a';
    vector<int> a(26,0);
    vector<int> m(26,-1);
    bool flag = false;


    rep(j,s.length()) {
        rep(i, 26) {
            if(s[j] != (char)(c+i)) a[i] ++;
            else{
                m[i] = max(m[i],a[i]);
                a[i] = 0;
            }
        }
    }

    rep(i, 26) {
        m[i] = max(m[i],a[i]);
        a[i] = 0;
    }

 
    sort(m.begin(),m.end());

    rep(i,26){
        if(m[i] != -1) {
            cout << m[i];
            break;
        }
    }

    return 0;
}









