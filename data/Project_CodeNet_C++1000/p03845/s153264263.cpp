#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,temp1=0,temp2=0,temp3;
    cin>>n;
    int time[n];
    for(i=0;i<n;i++)
    {
        cin>>time[i];
        temp1+=time[i];
    }
    cin>>m;
    int drink[m][2];
    for(i=0;i<m;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>drink[i][j];
        }
        temp2=drink[i][0];
        temp2=drink[i][1]-time[temp2-1];
        if(temp2>0)
            temp3=temp1+temp2;
        else if(temp2==0)
            temp3=temp1;
        else
            temp3=temp1+temp2;
        cout<<temp3<<endl;
    }

    return 0;
}
