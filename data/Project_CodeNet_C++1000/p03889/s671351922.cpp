#include<bits/stdc++.h>

using namespace std;
string a;
int main()
{
    cin>>a;
    int len=a.size();
    if(len%2==1) 
    {
        cout<<"No";
        cout<<endl;
        return 0;
    }
    int r=0;
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        if((a[i]=='p' && a[j]=='q') || (a[i]=='q' && a[j]=='p') ||(a[i]=='d' && a[j]=='b') || (a[i]=='b' && a[j]=='d')) ;
        else 
        {
            r=1;
            break;
        }
    }
    if(r==0) cout<<"Yes";
    else cout<<"No";
    cout<<endl;
    
    return 0;
}