#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    
    string ans;
    if (a == b) {
        ans = "Draw";
    } else if (a == 1) {
        ans = "Alice";
    } else if (b == 1) {
        ans = "Bob";
    } else if (a > b) {
        ans = "Alice";
    } else {
        ans = "Bob";
    }
    
    cout << ans << endl;
}
