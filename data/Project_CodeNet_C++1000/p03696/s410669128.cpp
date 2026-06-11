#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){
        
    int N; cin >> N;
    string S;cin >> S;
    
    int need_left = 0;
    int pointer = 0;
    for(int i = 0; i < S.size();i++){
        if(S[i]=='(')++pointer;
        else{
            if(pointer == 0)++need_left;
            else pointer--;
        }
    }
    
    int need_right = pointer;
    
    string res ="";
    for(int i = 0; i < need_left;i++)res += '(';
    res += S;
    for(int i = 0; i < need_right;i++)res += ')';
    cout << res << endl;
    
    
}

