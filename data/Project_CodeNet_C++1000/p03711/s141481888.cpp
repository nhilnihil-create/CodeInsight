#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int a,b;
    int x[]= {4,6,9,11};
    int y[]= {1,3,5,7,8,10,12};
    cin>>a>>b;
    if(a==2||b==2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    int f=0;
    for(int i=0; i<4; i++)
    {
        if(a==x[i])
        {
            for(int i=0; i<4; i++)
            {
                if(b==x[i])
                {
                    cout<<"Yes"<<endl;
                    f=1;
                    return 0;
                }
            }
        }
    }
    if(f==0)
    {
        for(int i=0; i<7; i++)
        {
            if(a==y[i])
            {
                for(int i=0; i<7 ;i++)
                {
                    if(b==y[i])
                    {
                        cout<<"Yes"<<endl;
                        f=1;
                        return 0;
                    }
                }
            }
        }
    }
    if(f==0) cout<<"No"<<endl;
    return 0;
}
