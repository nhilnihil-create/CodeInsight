#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin >> s;
    while (s.size()>0){
        if (s[0]!='A'){
            s.erase(s.begin()+0);
        }
        else  break;
    }
    while (s.size()>0){
        if (s.back()!='Z'){
            s.erase(s.begin()+s.size()-1);
        }
        else break;
    }
    cout << s.size();
    
}