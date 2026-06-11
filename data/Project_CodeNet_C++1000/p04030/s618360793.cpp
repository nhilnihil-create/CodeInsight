// バイナリハックイージー
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<char> v;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='B' && v.size()!=0){
            v.pop_back();
        }
        else if(s[i]!='B'){
            v.push_back(s[i]);
        }
    }
    for(int i=0;i<v.size(); i++){
        cout << v[i];
    }
    cout << endl;
    return 0;
}