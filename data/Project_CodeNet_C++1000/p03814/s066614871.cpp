#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    int l = s.size(), r = 0; 
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A' && l > i) l = i;
        if(s[i] == 'Z' && r < i) r = i;
    }
    cout << r - l + 1 << endl;
}