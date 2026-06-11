#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    bool present[26] = {false};
    for(int i=0; i<s.size(); i++){
        if(s[i]>='a' && s[i]<='z'){
            present[s[i]-'a'] = true;
        }
    }
    for(int i=0; i<26; i++){
        if(present[i]==false){
            cout << (char)(i+'a');
            return 0;
        }
    }
    cout << "None" <<endl;
}