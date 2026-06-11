#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    vector<int> cnt(26);
    for(int i=0; i<s.size(); i++){
        cnt.at(s[i]-'a')++;
    }

    for(int i=0; i<26; i++){
        if(cnt.at(i) == 0){
            char c = i+'a';
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}