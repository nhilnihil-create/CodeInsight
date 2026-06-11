#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    string s;
    cin >> s;
    map<char,int> mp;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
    }
    for(auto it : mp){
        if(it.second >= 2){
            cout << "no" <<endl;
            return 0;
        }
    }
    cout << "yes" <<endl;
}