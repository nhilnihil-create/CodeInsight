/**
 *  author:   TakeruOkuyama
 *  created:  
**/
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

int main(){
    string S;
    cin >> S;
    bool N = false, W = false, SS = false, E = false;
    rep(i, S.size()){
        if(S[i] == 'N'){
            N = true;
        }else if(S[i] == 'W'){
            W = true;
        }else if(S[i] == 'S'){
            SS = true;
        }else if(S[i] == 'E'){
            E = true;
        }
    }
    if(N == SS && W == E){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
return 0;}

/**
 * g++ code.cpp
 * ./a.out
 * shift + ctrl + i
**/ 