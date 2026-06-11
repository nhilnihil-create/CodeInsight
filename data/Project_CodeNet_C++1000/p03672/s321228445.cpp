#include <bits/stdc++.h>
using namespace std;
bool Check(string input){
    
    if(input.size()%2 == 1){
        return false;
    }
    else{
        int len = input.size() / 2;
        for(int i=0;i<len;i++){
            if(input[i] != input[i+len]) return false;
        }
        return true;
    }
}
int main(void){
    
 string S;
 cin >> S;
 int N = S.size();
 
 for(int i=N-1;i>=0;i--){
    if(Check(S.substr(0,i))){cout << S.substr(0,i).size() << endl; return 0;}
 } 
}