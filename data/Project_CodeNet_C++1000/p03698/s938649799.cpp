#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool flg = true;
    map<char, int> mp;
    for(int i=0; i<26; i++){
        mp['a'+i] = 0;
    }
    for(int i=0; i<s.length(); i++){
        mp[s.at(i)]++;
        if(mp[s.at(i)]>1){
            flg = false;
            break;
        }
    }
    if(flg)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}