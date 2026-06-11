#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long q,h,s,d,n;
    cin>>q>>h>>s>>d;
    cin>>n;
    long long a[3],b[4];
    a[0]=4*q;
    a[1]=2*h;
    a[2]=s;
    b[0]=2*a[0];
    b[1]=2*a[1];
    b[2]=2*a[2];
    b[3]=d;
    sort(a,a+3);
    sort(b,b+4);
    cout<<(n/2)*b[0]+(n%2)*a[0]<<endl;
    return 0;
}
