#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    string s;
    cin >> s;
    int len = s.size();
    map<char,int>mp{};
    
    for(int i=0;i<len;i++){
        mp[s[i]] = 1;
    }
    
    if(len == mp.size()) cout << "yes" << endl;
    else cout << "no" <<endl;
}