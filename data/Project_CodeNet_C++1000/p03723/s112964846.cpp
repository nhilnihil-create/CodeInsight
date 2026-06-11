#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,aa,bb,cc,i;
    cin>>a>>b>>c;
    aa=a,bb=b,cc=c;
    if(aa%2||bb%2||cc%2)
        cout<<"0"<<endl;
    else if(a==b&&b==c)
        cout<<"-1"<<endl;
    else
    {
        for(i=1;; i++)
        {
            a=aa,b=bb,c=cc;
            if(aa%2||bb%2||cc%2)
            {
                cout<<i-1<<endl;
                break;
            }
            aa=(b/2)+(c/2);
            bb=(a/2)+(c/2);
            cc=(a/2)+(b/2);
        }
    }
}
