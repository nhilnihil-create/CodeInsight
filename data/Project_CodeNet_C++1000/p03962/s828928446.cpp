#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    int a,b,c;
    cin >> a >> b >> c;
    int count = 0;
    if ( a == b && b ==  c) {
        count = 1;
    } else if (a == b && b != c) {
        count = 2;
    } else if (a == c && b != c) {
        count = 2;
    } else if ( a != c && b == c) {
        count = 2;
    } else {
        count = 3;
    }
    cout << count << endl;
    return 0;
}

