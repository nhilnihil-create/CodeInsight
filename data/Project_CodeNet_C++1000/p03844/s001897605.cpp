#include<bits/stdc++.h>
#include<string>
using namespace std;

typedef long long int lli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    lli a, b;
    char ch;

    cin >> a >> ch >> b;
    if(ch == '+')
    {
        cout << a + b;
    }
    else
    {
        cout << a- b;
    }
}
