#include <bits/stdc++.h>
using namespace std;
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20);} } fast;

int main() {
    int c = 0;
    string s;
    string f = "CODEFESTIVAL2016";
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != f[i]){
            c = c + 1;
        }
    }
    cout << c << endl;
}