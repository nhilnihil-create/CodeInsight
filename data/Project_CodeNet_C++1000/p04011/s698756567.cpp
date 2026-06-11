#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
int main()
{
    
    LL t = 1;
    //cin >> t;
    
    while(t--)
    {
        LL n , k , x , y;
        cin >> n >> k >> x >> y;
        
        if(n <= k)
            cout << x * n;
        else
            cout << x * k + y * (n - k);
    }

    return 0;
}