#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#define LL long long
#define maxn 100010
using namespace std;
string a,b;
int main()
{
    char x;
    int i,l,r;
    a="10";
    int sum=0;
    int di=0;
    do
    {
        di++;
        cout<<"? "<<a<<endl;
        cin>>x;
        a+='0';
    }while (x=='Y'&&di<=9);
    if (di==10)
    {
        di=1;
        a='2';
        cout<<"? "<<a<<endl;
        cin>>x;
        if (x=='Y')
        {
            cout<<"! 1"<<endl;
            return 0;
        }
        a+='2';
        do
        {
            di++;
            cout<<"? "<<a<<endl;
            cin>>x;
            a+='2';
        }while (x=='N');
    }
    for (i=0;i<di-1;i++)
    {
        l=0,r=9;
        b+='0';
        while(l<r)
        {
            int mid=(l+r)/2+1;
            b[i]=mid+'0';
            cout<<"? "<<b<<endl;
            cin>>x;
            sum++;
            if (x=='Y') l=mid;
            else r=mid-1;
        }
        b[i]=l+'0';
    }
    b+='0';
    a=b;
    a+='0';
    r=9;
    if (di==1) l=1;
    else l=0;
    while (l<r)
    {
        int mid=(l+r)/2;
        a[di-1]=mid+'0';
        cout<<"? "<<a<<endl;
        cin>>x;
        sum++;
        if (x=='Y') r=mid;
        else l=mid+1;
    }
    b[di-1]=l+'0';
    /*for (;i<=9;i++)
      {
      a[di-1]=i+'0';
      cout<<"? "<<a<<endl;
      cin>>x;
      sum++;
      if (x=='Y') break;
      }
      b[di-1]=i+'0';*/
    cout<<"! "<<b<<endl;
}
