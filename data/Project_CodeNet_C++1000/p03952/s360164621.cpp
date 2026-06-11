#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main()
{
    int n,x,i,j,k;
    cin >> n >> x;
    if(n==1)
    {
        if(x==1) cout << "Yes" << endl << 1 << endl;
        else cout << "No" << endl;
    }
    else if(n==2)
    {
        if(x==2) cout << "Yes" << endl << 1 << endl << 2 << endl << 3 << endl;
        else cout << "No" << endl;
    }
    else
    {
        if(x==1 || x==(2*n-1))
            cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
            a[n] = x;
            if(x==(2*n-2))
            {
                a[n-1]=x+1;
                a[n-2] = x-1;
                a[n+1] = x-2;
                j=x-3;
                k=x+2;
            }
            else
            {
                a[n-1]=x-1;
                a[n-2]=x+1;
                a[n+1]=x+2;
                j=x-2;
                k=x+3;
            }
            for(i=1;i<=2*n-1;i++)
            {
                if(a[i]==0)
                {
                    if(j>=1)
                    {
                        a[i]=j;
                        j--;
                    }
                    else if(k<=2*n-1)
                    {
                        a[i]=k;
                        k++;
                    }
                }

            }
            for(i=1;i<=2*n-1;i++)
            {

                cout << a[i] << endl;
            }

        }

    }

}
