#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s,t;
    cin >> n >> s >> t;
    int x = n*2;
    for(int i = 0; i < n; i++){
        if(s.substr(n-i-1,i+1) == t.substr(0,i+1)){
            int y = t.substr(0,i+1).size();
            x = min(x,2*n-y);
        }
    }
    cout << x << endl;
    return 0;
}