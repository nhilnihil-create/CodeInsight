#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    for(char c = 'a'; c <='z'; c++){
        bool isFound = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i]==c){
                isFound = true;
                break;
            }
        }
        if(isFound==false){
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}