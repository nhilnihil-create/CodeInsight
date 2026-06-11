#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] != s[i+1]) ans++;  
    }   
    cout << ans << endl;
}