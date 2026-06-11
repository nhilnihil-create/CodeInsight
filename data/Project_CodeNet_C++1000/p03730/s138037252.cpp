#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int lhs = c%b;
    int temp = a%b;
    for(int i=0;i<=b-1;i++)
    {
        if( (i*temp)%b  == lhs )
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}