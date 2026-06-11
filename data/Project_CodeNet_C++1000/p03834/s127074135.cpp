#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == ',') cout << " ";
        else cout << s[i];
    }    
}