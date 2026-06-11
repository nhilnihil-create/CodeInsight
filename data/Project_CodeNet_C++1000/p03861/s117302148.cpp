#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long int
using namespace std;
void Solve()
{
    ll a, b, x;

    while(cin >> a)
    {
        ll counter = 0;
        cin  >>  b >> x;
        ll up = a  - (a%x);
        ll down = b - (b%x);
        down = ((down - up)/x);
        if(a%x == 0) down++;
        cout << down << '\n';
    }

}

int main()
{
    //int t;
    //cin >> t;
  //  while (t--)
    {
        Solve();
       // cout << '\n';
    }
    return 0;
}

