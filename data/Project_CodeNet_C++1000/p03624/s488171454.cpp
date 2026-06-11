#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    string s;
    cin >> s;
    vector<int> hash(26, 0);
    for(int i=0; i<(int)s.length(); ++i){
        hash[s[i]-'a']++;
    }

    for(int i=0; i<26; ++i){
        if(hash[i] == 0){
            char c = 'a'+i;
            cout << c;
            return 0;
        }
    }
    cout << "None";
    return 0;
}
