#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int x,a,b;
    cin>>x>>a>>b;
    if(a>=b)cout<<"delicious"<<endl;
    else
    {
        if(x>=abs(a-b))cout<<"safe"<<endl;
        else cout<<"dangerous"<<endl;
    }

}
