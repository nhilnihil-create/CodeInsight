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
    for(char i = 'a'; i <= 'z'; i++){
        mp[i] = 0;
    }
    rep(i, 0, s.size()){
        mp[s[i]] ++;
    }
    for(char i = 'a'; i <= 'z'; i++){
        if(mp[i] == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}

