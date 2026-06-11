#include<bits/stdc++.h>
using namespace std;
#define ll long long
int fact(int n)
{
    if(n==0) return 0;
    return n+fact(n-1);
}
int main()
{

int n;
cin>>n;
cout<<fact(n);
return 0;
}
