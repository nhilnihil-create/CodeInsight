#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;
    int K;
    cin >> S >> K;
    for(int i = 0; i < S.size();i++){
        char C = S[i];
        int todo = 'z' - C + 1;
        if(C == 'a')continue;
        if(K >= todo){
            S[i] = 'a';
            K -= todo;
        }
    }
    K %= 26;
    for(int i = S.size()-1; i>=0;i--){
        if(K > 0){
            char C = S[i];
            C += K;
            S[i] = C;
            K = 0;      
        }
    }
    cout << S << endl;
    
}
