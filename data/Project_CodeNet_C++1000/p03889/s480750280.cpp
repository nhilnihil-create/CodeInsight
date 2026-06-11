#include<bits/stdc++.h>
using namespace std;
int main()
{
    char inn;
    int i=1;
    int jud[100005];
    while(cin>>inn)
    {
        if(inn=='b')
            jud[i]=1;
        else if(inn=='d')
            jud[i]=4;
        else if(inn=='p')
            jud[i]=2;
        else if(inn=='q')
            jud[i]=3;
        i++;
    }
    if((i-1)%2==0)
    {
        for(int j=1;j<=(i-1)/2;j++)
        {
            if(jud[j]+jud[i-j]!=5)
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
        return 0;
    }
    else
        cout<<"No"<<endl;
        return 0;
}