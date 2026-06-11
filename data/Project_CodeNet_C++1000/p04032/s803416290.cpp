#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();

    int a = -1, b = -1;
    for(int i=0; i<n; i++){
        if(i <= n-2 && s[i] == s[i+1]){
            a = i+1;
            b = i+2;
            break;
        }
        if(i <= n-3 && s[i] == s[i+2]){
            a = i+1;
            b = i+3;
            break;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}