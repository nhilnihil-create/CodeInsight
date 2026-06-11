#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=0;cin>>n;int ar[n];for(int i=0;i<n;i++){cin>>ar[i];s+=ar[i];}
    int m;cin>>m;
    while(m--)
    {
        int pos,a;cin>>pos>>a;
        cout<<s+(a-ar[pos-1])<<endl;
    }
}
