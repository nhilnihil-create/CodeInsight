#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,a,b;
    cin>>x>>a>>b;
    string s;
    if(b-a<=0)
        cout<<"delicious\n";
    else if(b-a<=x)
        cout<<"safe\n";
    else
        cout<<"dangerous\n";
}
