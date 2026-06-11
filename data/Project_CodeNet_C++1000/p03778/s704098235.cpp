#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w,a,b,ans=0;
    cin>>w>>a>>b;
    if(a>b)
        swap(a,b);
    cout<<((w+a)>b?ans:b-(w+a))<<endl;
}
