#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    
    cin >> s;
    int n = s.size();
    
    int start = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='A') {
            // cout << "ok";
            start = i;
            break;
        }
    }
    
    int end = 0;
    for(int i=n;i>=0;i--){
        if(s[i]=='Z'){
            end = i;
            break;
        }
    }
    cout << end - start +1;
    return 0;
}
