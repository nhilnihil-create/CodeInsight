#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int solver(string s){

    int N = s.size();
    string buf = s;

    int del;
    if(N == 2) return 1;
    else if(N%2 == 0) del = 2;
    else del = 1;

    int ans = 0;
    while(N-del < N){
        string l, r;
        for(int j = 0; j != (N-del)/2; ++j) l += buf.at(j);
        for(int k = (N-del)/2; k != N-del; ++k) r += buf.at(k);
        del += 2;

        if(l == r){
            ans = l.size() + r.size();
            break; 
        }
    }

    return ans;
}

int solver2(string s){

    int N = s.size();

    int del = 0;
    if(N == 2) return 2; 
}

int main(){

    string s;
    cin >> s;

    cout << solver(s) << endl;
    cerr << solver2(s) << endl;
    
    return 0;
}