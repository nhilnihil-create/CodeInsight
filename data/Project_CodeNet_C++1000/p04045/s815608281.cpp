#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,j,a[10],flag;
    string str;
    fill(a,a+10,0);
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        cin>>j;
        a[j]=1;
    }
    for(i=n;;i++)
    {
        flag=0;
        std::string str = std::to_string(i);
        for(j=0;str[j];j++)
        {
            if(a[str[j]-'0']==1)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            cout<<str<<endl;
            break;
        }
    }
}
