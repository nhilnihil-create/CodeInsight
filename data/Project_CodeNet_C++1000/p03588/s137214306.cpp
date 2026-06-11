#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    int lowest_a = 0,lowest_b = 0;
    for(int i = 0;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a > lowest_a)
        {
            lowest_a = a;
            lowest_b = b;
        }
    }
    cout << lowest_a + lowest_b;

    return 0;
}