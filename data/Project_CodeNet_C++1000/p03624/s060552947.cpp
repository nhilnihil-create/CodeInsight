#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    string s;
    cin >> s;

    map<char,int> mp;

    for(char c = 'a';c <= 'z';c++){
        mp[c] = 0;
    }

    rep(i, s.size()){
        mp[s[i]]++;
    }

    for(char c = 'a';c <= 'z';c++){
        if(mp[c] == 0){
            cout << c << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}