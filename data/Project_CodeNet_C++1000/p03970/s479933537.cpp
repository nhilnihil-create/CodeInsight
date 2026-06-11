#include <bits/stdc++.h>
using namespace std;

int main(void){

    string M = "CODEFESTIVAL2016";
    string S;
    cin >> S;
    
    int cont = 0;
    for(int i = 0; i < S.size();i++){
       if(M[i]!=S[i])cont++; 
    }
    

    cout << cont << endl;    
}
