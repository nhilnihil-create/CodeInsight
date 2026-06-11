#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    map<char, int> mp;
    for(int i=0; i<26; i++){
        mp['a'+i] = 0;
    }
    for(int i=0; i<s.length(); i++){
        mp[s.at(i)]++;
    }

    bool flg = true;
    int ids = 0;
    for(int i=0; i<26; i++){
        if(mp['a'+i] == 0){
            flg = false;
            ids = i;
            break;
        }
    }
    char res = 'a'+ids;
    if(flg)
        cout << "None" << endl;
    else
        cout << res << endl;

    return 0;
}