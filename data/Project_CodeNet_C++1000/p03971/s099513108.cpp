#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,a,b;
    cin >> n >> a >> b;
    char c[n];
    for(ll i=0;i<n;i++)
    {
        cin >> c[i];
    }
    ll sum;
    sum = a + b;
    for (ll i=0;i<n;i++)
    {
        if(c[i]=='c')
        {
            cout << "No" << endl;
        }
        else if(c[i] =='a' )
        {
            if(sum!=0)
            {printf("Yes\n");
            sum--;}
            else
                printf("No\n");
        }
        else if(c[i]== 'b'  )
        {
            if(sum!=0 && b!=0)
            {
                 printf("Yes\n");
                 sum--;
                 b--;
            }
            else
                printf("No\n");
        }
    }
}

