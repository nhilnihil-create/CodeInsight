#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    string s;
    cin >> s;

    int sSize = s.size() - 1;
    if(sSize % 2){
        sSize = sSize - 1;
    }
    
    ll res = sSize/2;
    ll output = 0;
    for(int i = res; i >= 1; i--){
        string s0 = s.substr(0, i);
        string s1 = s.substr(i, i);
        // cout << s0 << " : " << s1 << endl;
        if(s0 == s1){
            output = i * 2;
            break;
        }
    }

    cout << output << endl;

}