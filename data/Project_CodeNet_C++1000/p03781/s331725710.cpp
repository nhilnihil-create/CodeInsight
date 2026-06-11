#include<iostream>
using namespace std;
typedef long long LL;
int f(int x)
{
    for(LL n = 1; n <= x; n++)
        if(n*(n+1)/2 >= x)
            return n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x; cin >> x;
    cout<<f(x)<<endl;

    cout<<flush;
    return 0;
}