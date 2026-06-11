#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans = "CODEFESTIVAL2016";
    int n = 0;
    for(int i = 0; i < 16; i++){
        if(s[i] != ans[i]){
            n++;
        }
    }
    cout << n << endl;
    return 0;
}