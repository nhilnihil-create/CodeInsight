#include<bits/stdc++.h>
using namespace std;

int mod = 1'000'000'007;

int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<char> tmp;
    for (int i = 0; i < n; i++){
        if (s[i] == t[i]) tmp.push_back('A');
        else {
            tmp.push_back('B');
            i++;
        }
    }
    long long dp;
    if (tmp[0] == 'A') dp = 3;
    else dp = 6;
    for (int i = 1; i < tmp.size(); i++){
        if (tmp[i-1] == 'A'){
            dp *= 2;
            dp %= mod;
        }
        else if (tmp[i] == 'B'){
            dp *= 3;
            dp %= mod;
        }
    }
    cout << dp << endl;
}