#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s;
    cin >> s;

    string ans = "";
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '0') ans += '0';
        else if(s[i] == '1') ans += '1';
        else if(s[i] == 'B'){
            if(!ans.empty()){
                int l = ans.size();
                ans.erase(l-1);
            }
        }
    }
    cout << ans << endl;

    return 0;
}