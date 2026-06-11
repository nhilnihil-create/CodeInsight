#include<bits/stdc++.h>
using namespace std;
int main()
{
long long a,b,c,d,x,y,e,f,g,h;
int arr[]={1,3,5,7,8,10,12};
int brr[]={4,6,9,11};
cin>>x>>y;
if(x==2&&y==2)
    cout<<"Yes";
else if((x==1||x==3||x==5||x==7||x==8||x==10||x==12)&&(y==1||y==3||y==5||y==7||y==8||y==10||y==12))
  cout<<"Yes";
  else if((x==4||x==6||x==9||x==11)&&(y==4||y==6||y==9||y==11))
  cout<<"Yes";
  else cout<<"No";
}
