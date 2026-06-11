#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LL x, y; cin >> x >> y;
    cout<<(abs(x-y) <= 1 ? "Brown" : "Alice")<<endl;

    cout<<flush;
    return 0;
}