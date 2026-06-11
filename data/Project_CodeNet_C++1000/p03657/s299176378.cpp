#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    if((a%3==0)||(b%3==0)||(a+b)%3==0)
    {
        cout<<"Possible"<<endl;
    }
    else
    {
        cout<<"Impossible"<<endl;
    }
    return 0;
}