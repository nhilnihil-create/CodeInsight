#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int a,b,x, i = 0;

    cin>> a>> b>> x;

    if( a% x == 0) i++;

    i += ((b/x)-(a/x));

    cout<< i<< endl;

    return 0;
}
