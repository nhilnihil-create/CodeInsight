#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, a, b;
    cin >> x >> a >> b;
    string result = "dangerous";
    
    if ((a - b) >= 0) {
        result = "delicious";
    } else if ((b - a) <= x){
        result = "safe";
    }
    
    cout << result << endl;
}
