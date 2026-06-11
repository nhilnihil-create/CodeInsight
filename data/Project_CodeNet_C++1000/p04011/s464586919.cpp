#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k;
    int x;
    int y;
    int m;

cin>>n>>k>>x>>y;

    if ((n - k) > 0)
    {
        m = k*x+(n-k)*y;
        cout<<m<<endl;
    }
    else
    {
        m =n*x;
        cout<<m<<endl;
    }



    return 0;
}
