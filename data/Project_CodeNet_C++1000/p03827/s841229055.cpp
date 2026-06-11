#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int x = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'I'){
            x++;
        }
        else if(s[i] == 'D'){
            x--;
        }
        if(ans < x) ans = x;
    }
    cout << ans << endl;


    return 0;
}