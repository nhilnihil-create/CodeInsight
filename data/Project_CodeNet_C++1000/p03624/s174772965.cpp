#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#define int long long
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

signed main() {

    string s;
    map<char,bool> mp;

    cin >> s;

    for(int i = 0; i < 26; i ++){
        mp[(char)('a' +i)] = false;
    }

    for(int i = 0; i < s.length(); i ++){
        mp[s[i]] = true;
    }
    for(int i = 0; i < 26; i ++) {
        if(mp[(char)('a' +i)] == false){
            cout << (char)('a' +i);
            break;
        }
        if(i == 25) cout << "None";
    }

    return 0;
}