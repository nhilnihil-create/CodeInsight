#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(i%2 == 0) cout << s[i];
    }
    cout << endl;
}