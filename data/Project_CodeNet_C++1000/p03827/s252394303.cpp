#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int x = 0, ans = 0;
    for(char c : s){
        if(c == 'I') x++;
        else x--;
        if(x > ans) ans = x;
    }
    cout << ans << endl;
}