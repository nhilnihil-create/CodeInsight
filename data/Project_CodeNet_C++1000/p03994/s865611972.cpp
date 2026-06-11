#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define MOD 1000000007
#define el endl
#define INF 1e8
typedef long long ll;
typedef long double ld;
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25
int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    
    rep(i, s.length()){
        char c = s[i];
        int d = c == 'a' ? 0 : 26 - ((int)c - 97);
        if(d <= k){
            s[i] = 'a';
            k -= d;
        }
    }
    if(k != 0){
        int a = s.back() - 'a';
        a += k;
        a %= 26;
        s.back() = 'a' + a;
    }
    cout << s << endl;
}


