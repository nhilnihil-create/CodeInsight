#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;;i++)
    {
        int a=pow(2,i);
        if(a==n)
        {
            cout<<a<<"\n";
            return 0;
        }
        if(a>n)
        {
            cout<<pow(2,i-1)<<"\n";
            return 0;
        }
    }
}