#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(abs(b-a)<abs(c-a))
        cout<<"A";
    else cout<<"B";

    return 0;
}