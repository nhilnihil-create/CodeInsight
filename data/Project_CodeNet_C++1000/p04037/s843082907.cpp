#include <bits/stdc++.h>  
using namespace std; 
int n;
int a[100005];
int st;
int l=0,r=0;
inline bool comp(int x,int y){return x>y;}
int main()  
{  
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,comp); 
    for(int i=1;i<=n+1;i++)
        if(a[i]<i)
        {
            st=i-1;
            break;
        }
    l=a[st]-st;
    r=-1;
    for(int i=st;a[i]>=st;i++)r++;
    //cout<<st<<" "<<l<<" "<<r<<endl;
    l%=2;
    r%=2;
    if(l||r)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    return 0;
}