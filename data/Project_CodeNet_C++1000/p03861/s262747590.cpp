#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c;cin >> a >> b >> c;
    if (c==1)cout << b-a+1;
    else if (a%c==0)cout << (b/c)-(a/c)+1;
    else cout << (b/c)-(a/c);

    
}
