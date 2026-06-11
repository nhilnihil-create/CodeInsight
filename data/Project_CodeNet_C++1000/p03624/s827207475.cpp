#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    vector<int> dict(26, 0);
    cin >> s;
    for (int i=0; i<s.size(); i++) dict[s[i]-'a'] = 1;
    for (int i=0; i<26; i++){
        if (dict[i] == 0){
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}