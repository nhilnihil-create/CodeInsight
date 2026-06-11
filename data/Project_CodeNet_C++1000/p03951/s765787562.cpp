#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int i;
    for(i = 0; i < n; i++){
        bool flag = true;
        for(int j = i; j < n; j++){
            if(s[j] != t[j-i]) flag = false;
        }
        if(flag) break;
    }
    cout << n + i << endl;
    return 0;
}
