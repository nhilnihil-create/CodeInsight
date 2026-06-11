#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string S;
    cin >> S;

    int num_N = 0;
    int num_S = 0;
    int num_W = 0;
    int num_E = 0;

    for(int i=0; i<S.size(); i++){
        if(S[i]=='N'){num_N++;}
        if(S[i]=='S'){num_S++;}
        if(S[i]=='W'){num_W++;}
        if(S[i]=='E'){num_E++;}
    }

    if(num_N == num_S || num_N*num_S > 0){
        if(num_W == num_E || num_W*num_E > 0){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;

}