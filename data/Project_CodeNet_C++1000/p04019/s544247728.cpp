#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    string S;
    cin >> S;
    bool n = false,e = false,w = false,s = false;
    rep(i,S.size()){
        if(S[i] == 'N'){
            n = true;
        }
        if(S[i] == 'E'){
            e = true;
        }
        if(S[i] == 'W'){
            w = true;
        }
        if(S[i] == 'S'){
            s = true;
        }
    }
    if(n && s && w && e)cout << "Yes";
    else if(n && s && (!w && !e))cout << "Yes";
    else if(w && e && (!n && !s))cout << "Yes";
    else cout << "No";
}