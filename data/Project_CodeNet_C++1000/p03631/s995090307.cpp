#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    string s;
    cin >> s;
    string t = s;
    bool a = true;
    reverse(t.begin() , t.end());
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]){
            a = false;
        }
    }
    if(a){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
