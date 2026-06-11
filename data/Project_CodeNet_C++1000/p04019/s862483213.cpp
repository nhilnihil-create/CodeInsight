#include <bits/stdc++.h>
using namespace std;


int main(void){
 
    string S;
    cin >> S;
    
    map<char,int> mp;
    string ans = "Yes";
    for(int i = 0; i < S.size(); i++){
        mp[S[i]]++;
    }
    
    
    
    if(mp['N'] == 0 && mp['S'] !=  0)ans ="No";
    if(mp['N'] != 0 && mp['S'] ==  0)ans ="No";
    if(mp['E'] == 0 && mp['W'] !=  0)ans ="No";
    if(mp['E'] != 0 && mp['W'] ==  0)ans ="No";
    cout << ans << endl;

}
 