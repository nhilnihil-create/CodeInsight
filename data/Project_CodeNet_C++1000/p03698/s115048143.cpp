#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int a = 1;
    char c = s[0];
    for(int i = 1; i < s.size(); i++){
        if(c != s[i]) a++;
        c = s[i];
    }
    if(a == s.size()) puts("yes");
    else puts("no");
}