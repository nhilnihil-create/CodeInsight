
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,i,sum=0,p=2;
    cin >> t;
    t = 3*t;
    long long int a[t];
    for(i=0;i<t;i++)
    {
        cin >>a[i];

    }
    sort(a,a+t);
    for(i=0;i<t;i=i+3)
    {sum= sum+a[t-p];
    p=p+2;}
    cout<<sum;
    return 0;

}
