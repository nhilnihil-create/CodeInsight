#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    if(abs(n-m)<=1) cout<<"Brown"<<endl;
    else cout<<"Alice"<<endl;
    return 0;
}
