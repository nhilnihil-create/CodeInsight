#include <bits/stdc++.h>
using namespace std;
const int uchiha=1e3+5;
int main()
{
long long n,c1=0;
cin>>n;
while(n>0){
    c1++;
    n-=c1;
}
cout<<c1;
}