#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    for (int k=1; k<=b; k++)
    {
        if(abs(k*a - c) % b == 0)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
