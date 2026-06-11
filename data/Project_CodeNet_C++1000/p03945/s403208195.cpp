#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    char tmp = s[0];
    for(char x : s){
        if(x != tmp){
            tmp = x;
            ans++;
        }
    }
    cout << ans << endl;
}