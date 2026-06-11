//BISMILLAHIR RAHMANIR RAHIM

#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define pi acos(-1.00)

using namespace std;



int main()
{
long long int a[4],i,count=0,p=0;
for(i=0;i<3;i++)
    cin>>a[i];
for(i=0;i<3;i++)
{
    if(a[i]==5)
        count++;
    else if(a[i]==7)
        p++;
}
if(count==2&&p==1)
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
}

