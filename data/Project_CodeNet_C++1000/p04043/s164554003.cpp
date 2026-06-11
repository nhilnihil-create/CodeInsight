#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[3],cnt5=0,cnt7=0;
    for(int i=0;i<3;i++)
    {
        cin>>ar[i];
        if(ar[i]==5)
        {
            cnt5++;
        }
        else
        {
            cnt7++;
        }
    }
    if(cnt5==2 && cnt7==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
