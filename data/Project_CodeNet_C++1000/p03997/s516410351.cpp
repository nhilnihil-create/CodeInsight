#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    int a,b,h;
    cin >> a >> b >> h;
    long long result = 0;
    result = (a+b) * (h/2);
    cout << result << endl;
    return 0;
}

