#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i, 0, s.size()){
        mp[s[i]]++;
    }
    for(char i = 'a'; i <= 'z'; i++){
        if(mp[i] > 1){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}

