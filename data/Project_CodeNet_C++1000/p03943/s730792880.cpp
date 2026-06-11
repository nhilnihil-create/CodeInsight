#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    int a,b,c;
    cin >> a >> b >> c;
    if ((a+b == c) || (a+c == b) || (b+c == a)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

