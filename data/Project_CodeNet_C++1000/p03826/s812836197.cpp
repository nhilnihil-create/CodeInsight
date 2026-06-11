#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int result = max (a*b, c*d);
    cout << result << endl;
    return 0;
}

