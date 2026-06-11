#include<bits/stdc++.h>
using namespace std;
int c[26];
int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++)c[(s[i]-'a')]++;
    for(int i=0;i<26;i++){
        if(c[i]==0){
            cout << (char)('a'+i);
            return 0;
        }
    }
    cout << "None";
}