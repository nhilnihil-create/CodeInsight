#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    cin >> S;
    
    int Length = S.length();
    
    string ans = "";
    
    for(int i = 0; i < Length; ++i){
        if(i % 2 == 0){
            ans += S[i];
        }
    }
    
    cout << ans << endl;
}