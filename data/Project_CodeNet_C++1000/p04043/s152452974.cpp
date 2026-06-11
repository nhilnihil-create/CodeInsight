
#include <bits/stdc++.h>
using namespace std;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

#define ASSERT(expr...) assert((expr))

signed main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    
    if (
       (a == 5 && b == 5 && c == 7) || 
       (a == 5 && b == 7 && c == 5) || 
       (a == 7 && b == 5 && c == 5) 
    ) {
        cout << "YES" << "\n" << endl;
    } else {
        cout << "NO" << "\n" << endl;
    }
    return 0;
}

