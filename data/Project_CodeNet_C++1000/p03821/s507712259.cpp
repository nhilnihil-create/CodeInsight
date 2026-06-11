#include<iostream>
using namespace std;
#define ll long long
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))

ll A[100005], B[100005];

int main()
{
    ll i,j,k,s,d,r,m,n, mid, cont=1;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>A[i]>>B[i];
        r = A[i] % B[i];
        if(r) A[i] = B[i] - r; else A[i] = 0;
    }

    for(i=n-1; i>=1; i--) if(A[i] < A[i+1])
    {
        d = A[i+1] - A[i];
        k = d / B[i];
        if(d % B[i]) k++;
        A[i] += k * B[i];
    }

    d = 0; s = 0;
    for(i=n; i>=1; i--)  s += A[i] - d, d = A[i];
    cout<<s<<endl;
    return 0;

}


