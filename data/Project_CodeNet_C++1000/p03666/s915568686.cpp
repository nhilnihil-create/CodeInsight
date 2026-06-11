#include <iostream>

using namespace std;
#define int long long

signed   main()
{
    int n , a , b , c , d;
    cin >> n >> a >> b >> c >> d;
    a = abs(a-b);
    b = 0;
    for(int i = 0; i <= n; i ++) {
        int l = a + c*i , r = a + d*i;
        int l1 = b + c*(n-i-1) , r1 = b + d*(n-i-1);
        if(l <= l1 && l1 <= r) {
            cout << "YES";
            return 0;
        }
        if(l <= r1 && r1 <= r) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
