#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int i,x,y,m=0,n,a,b;
    cin >> n >> a >>b;
    cin >> x;
    for(i=2;i<=n;i++)
    {
        cin >> y;
        if(a*(y-x)>b)
        {
            m+=b;
        }
        else
        {
            m+=a*(y-x);
        }
        x=y;
    }
    cout << m << endl;
    return 0;
}
