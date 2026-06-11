#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000

int main(){
    string s;
    cin >> s;
    int n = s.length();
    rep(i, n){
        rep(j, n){
            if(i == j) continue;
            if(s[i] == s[j]){
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;
    return 0;
}
