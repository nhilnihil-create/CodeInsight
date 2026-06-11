
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n , a , s=0;
    cin>>n>>a;
    if(a >= 2*n) {
        s = n;
        a -= 2*n;
        s += a / 4;
        cout << s << "\n";
    }
    else {
        cout << a / 2 << "\n";
    }

}
