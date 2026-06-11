#include <bits/stdc++.h>
using namespace std;
long long n ,k , x , y ,ans;
int main()
{

    cin >> n >> k >> x >> y;
     if (n > k)
    ans = x * k + y * (n - k);
    else 
        ans = x * n;
    cout <<ans << endl;

}


