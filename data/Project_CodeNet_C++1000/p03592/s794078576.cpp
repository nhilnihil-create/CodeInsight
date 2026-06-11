#include <string.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , m,k;
    cin>>n>>m>>k;
    bool answered = false;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(   i*m + j*n - 2*i*j == k)
            {
                cout<<"Yes";
                answered = true;
                break;
            }

        }
        if( answered )
            break;
    }
    if( !answered )
    {
        cout<<"No";
    }
}