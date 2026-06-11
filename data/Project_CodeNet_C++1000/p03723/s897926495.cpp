#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b,c;
    cin>>a>>b>>c;

    int sa=a,sb=b,sc=c;

    int cnt=0;

    while(!(sa%2||sb%2||sc%2))
    {
        int aa=sa/2,bb=sb/2,cc=sc/2;
        sa=bb+cc;
        sb=cc+aa;
        sc=aa+bb;
        cnt++;
        if(sa==a&&sb==b&&sc==c)
        {
            cout<<"-1\n";
            return 0;
        }
    }

    cout<<cnt<<"\n";

    return 0;
}
