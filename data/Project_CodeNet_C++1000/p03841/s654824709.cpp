#include<bits/stdc++.h>
using namespace std;
int a[260000],x[600];
int main()
{
    int i,j,n,k,l,cnt;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x[i];
        a[x[i]]=i;
    }
    sort(x+1,x+n+1);
    int ind = 1;
    for(i=1;i<=n;i++)
    {
        int pos = x[i];
        j=a[x[i]];
        k = j-1;
        while(k)
        {
            if(a[ind]==0)
            {
                a[ind] = j;
                ind++;
                k--;
            }
            else
            {
                if(ind==x[i])
                    break;
                ind++;
            }
        }
        if(k)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    for(i=1;i<=n;i++)
    {
        j=a[x[i]];

        for(k=j+1;k<=n;k++)
        {
            while(a[ind])
            {
                ind++;
            }
            if(ind<x[i] || ind>(n*n))
            {
                cout << "No" << endl;
                return 0;
            }
            a[ind] = j;
        }

    }


    cout << "Yes" << endl;
    for(i=1;i<=n*n;i++)
    {
        if(i>1) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    return 0;

}
