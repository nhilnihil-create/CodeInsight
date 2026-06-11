#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 
 
int main() {
    int h,w;
    cin >> h >> w;
    rep(i,h){
        vector<char>c(w);
        rep(j,w){
            cin >> c[j];
        }
        rep(k,w){
            cout << c[k];        
        }
        cout << endl;
        rep(k,w){
            cout << c[k];
        }
        cout << endl;

    }
}
