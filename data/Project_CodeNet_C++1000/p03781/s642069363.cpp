#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,c=0,i=1;
    cin >> n;
    while(n>0)
    {
        n -= i;
        c++;
        i++;
    }
    cout << c;
    return 0;

}
