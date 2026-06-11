#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int a,b,x,k;

    cin >> a >> b >> x;

    k=(b/x)-(a/x);

    if(a%x==0)
    {
        cout << k+1 <<endl;
    }
    else
        cout << k << endl;


    return 0;
}
