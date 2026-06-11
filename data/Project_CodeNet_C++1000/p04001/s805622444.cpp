#include <bits/stdc++.h>  
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define REP(i, a, op1, n, op2) for(int i=a; i op1 (int)(n); op2 ## op2 i)
#define cout(val) cout << (val) << endl

using namespace std;  

int main(){
    string s, c;
    cin >> s;
    int len = s.size() - 1;
    long long int result = 0;
    rep(i, 1<<len){
        rep(j, len){
            c.push_back(s[j]);
            if(i&1<<j && c != ""){
                result += stol(c);
                c = "";
            }
        }
        c.push_back(s[len]);
        if(c != ""){
            result += stol(c);
            c = "";
        }
    }
    cout(result);
}
