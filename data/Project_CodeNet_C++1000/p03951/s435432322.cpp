#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
//const int MOD = 1e9+7;

int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    int d=0;
    for(int i=0; i<=n; ++i){
        string ts = s.substr(n-i);
        string tt = t.substr(0, i);

        if(ts == tt){
            d = i;
        }
    }
    cout << n+n-d;
}
