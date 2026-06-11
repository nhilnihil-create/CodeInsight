#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int ss = 0;
    int ans = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'S') ss++;
        else {
            if(ss == 0) ans++;
            else ss--;
        }
    }
    cout << ans+ss << endl;
}