#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b;

    cin>>a>>b;

    if(a==0||b==0) cout<<"Zero\n";
    else if(a>0&&b>0)cout<<"Positive\n";
    else if(a<0&&b>0)cout<<"Zero\n";
    else
    {
        if((abs(a)-abs(min(0,b)))%2==0)cout<<"Negative\n";
        else cout<<"Positive\n";
    }    

    return 0;
}
