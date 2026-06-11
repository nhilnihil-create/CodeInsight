
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n , a , b , x ;
    cin>>n>>a>>b;
    if (abs(a-b)<=n)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<abs(a-b)-n<<endl;
    }
}
