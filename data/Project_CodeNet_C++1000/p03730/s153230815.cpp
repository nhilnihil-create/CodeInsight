#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int i, flag = 0;
    for(i = 1; i<=b; i++)
    {
        int p = a * i;
        if(p%b == c)
        {
            flag++;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
     cout<<"YES"<<endl;
     return 0;
}
