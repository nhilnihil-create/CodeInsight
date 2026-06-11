#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;
    cin >> S;
    
    reverse(S.begin(),S.end());
    for(int i = 0 ; i < S.size() ; ){
        if(S.substr(i,7) == "remaerd"){
            i+=7;
        }
        else if(S.substr(i,6) == "resare"){
            i+=6;
        }
        else if(S.substr(i,5) == "maerd"){
            i+=5;
        }
        else if(S.substr(i,5) == "esare"){
            i+=5;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}