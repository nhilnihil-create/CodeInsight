#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s, t;
    cin >> n >> s >> t;

    for(int i=0; i<=n; i++){
        string test = s.substr(0,i) + t;
        //cout << test << endl;
        if(test.substr(0,n) == s){
            cout << test.length() << endl;
            return 0;
        }
    }
    return 0;
}