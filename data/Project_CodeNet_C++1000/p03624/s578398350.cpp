#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    unordered_set<char> US;
    string ans = "a";
    for(int i = 0; i < S.size(); ++i) US.insert(S[i]);
    for(int i = 0; i < 26; ++i){
        if(US.find('a'+i) != US.end()){
            if('a'+i == 'z') ans = "None";
            else ans = 'a'+i+1;
        }
        else break;
    }
    cout << ans << endl;
    return 0;
}