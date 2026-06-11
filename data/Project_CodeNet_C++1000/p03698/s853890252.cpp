#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int func(int n){
    int cnt = 0;
    while(n){
        if(n%2 == 0){
            cnt++;
            n /= 2;
        }
        else{
            break;
        }
    }
    return cnt;
}
int main(){

    string s;
    cin >> s;
    map<char, int> mp;
    for(int i = 0; i < (int)s.size(); i++){
        mp[s[i]]++;
    }
    bool ok = true;
    for(auto c: mp){
        if(c.second > 1) ok = false;
    }
    if(ok) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}