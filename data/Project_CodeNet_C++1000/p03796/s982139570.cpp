// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>

#define int long long

using namespace std;

signed main()
{
    
    int n; cin >> n;
    
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * i;
        ans = ans % (int)(1e9 + 7);
    }
    
    //　出力
    cout << ans << endl;
}


// if (条件式)｛
     
//    }
