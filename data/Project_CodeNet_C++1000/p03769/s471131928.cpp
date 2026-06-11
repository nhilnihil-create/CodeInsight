#include <iostream>

using namespace std;

typedef long long LL;
int a[103];
int b[103];

int main()
{
    LL n;
    cin>>n;
    n++;

    int m=100;
    int i=0,j=0;
    while(n>1)
    {
        if(n&1) {a[i++]=m--;n--;}
        else {b[j++]=m--;n>>=1;}
    }

    cout<<2*(i+j)<<endl;
    for(int k=0;k<i;k++) cout<<a[k]<<' ';
    for(int k=j-1;k>=0;k--) cout<<b[k]<<' ';
    for(int k=m+1;k<=100;k++) cout<<k<<' ';

    return 0;
}