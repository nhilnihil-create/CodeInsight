#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int result;
    if (b < c || d < a) {
        result = 0;
    } else {
        result = min(b,d) - max(a,c);
    }
    
    cout << result << endl;
}
