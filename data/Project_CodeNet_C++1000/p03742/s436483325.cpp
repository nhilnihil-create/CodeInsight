#include<bits/stdc++.h>
using namespace std;
int main()
{
long long x,y;
cin>>x>>y;
long long z=abs(x-y);
if(z>=2)cout<<"Alice";
else cout<<"Brown";
return 0;
}