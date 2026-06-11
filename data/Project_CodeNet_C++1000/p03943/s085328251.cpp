#include <bits/stdc++.h>
using namespace std;

int main(){
    string ans = "No";
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a + b == c || a + c == b || b + c == a) {
        ans = "Yes";
    }
    
    cout << ans << endl;
}
