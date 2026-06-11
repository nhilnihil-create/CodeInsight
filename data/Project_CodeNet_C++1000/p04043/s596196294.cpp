//JI SRI KRISHNA.//
#include<iostream>
using namespace std;
int main()
{
    int a[4],f=0,s=0,i;
    for(i=0;i<3;i++)
    {
        cin>>a[i];
        if(a[i]==5)
            f++;
        if(a[i]==7)
            s++;
    }
   if(f==2&&s==1)
    cout<<"YES"<<endl;
   else
    cout<<"NO"<<endl;
}

