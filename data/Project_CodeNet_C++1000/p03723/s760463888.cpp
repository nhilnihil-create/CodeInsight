#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,c;
    cin>>a>>b>>c;
    int ans =0;
    if(a==b && b==c && c==a)
    {
        if(a%2==1 || b%2==1 || c%2==1)
        {
            cout<<"0"<<"\n";
            return 0;
        }
    }
    while(1)
    {
        if(a==b && b==c && c==a)
        {
            cout<<"-1";
            return 0;
        }
        else if((a%2==1) || (b%2==1) || (c%2==1))
        {
            cout<<ans<<"\n";
            return 0;
        }
        else
        {
            int aa,bb,cc;
            aa=a;
            bb=b;
            cc=c;
            a=(bb/2)+(cc/2);
            b=(aa/2)+(cc/2);
            c=(bb/2)+(aa/2);
        }
        ans++;
    }
}