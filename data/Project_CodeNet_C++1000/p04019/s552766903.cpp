#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    map<char, int> dict;
    for (int i=0; i<s.size(); i++){
        dict[s.at(i)]++;
    }

    bool flg = true;
    if (dict.count('N') != dict.count('S')) flg = false;
    if (dict.count('E') != dict.count('W')) flg = false;

    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}