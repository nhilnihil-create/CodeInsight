#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
void Main()
{
    int T,n,k;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        if(!n)
        {
            cout<<"Bob"<<endl;
            continue;
        }
        if(k % 3 != 0) cout<<(n % 3 == 0 ? "Bob" : "Alice")<<endl;
        else
        {
            if(n %(k+1) == 0)
            {
                cout<<"Bob"<<endl;
                continue;
            }
            int num = (n %(k+1) -1) / 3;
            if(num == (k-1)/3) cout<<"Alice"<<endl;
            else cout<<(n % (k+1) %3 == 0 ? "Bob" : "Alice")<<endl;
        }
    }
}
int32_t main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    cout<<(n*n-m)<<endl;
    return 0;
}
