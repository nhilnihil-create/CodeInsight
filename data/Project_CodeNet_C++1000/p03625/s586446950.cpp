#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    ll n;
    cin >> n;
    ll ar[n];
    for(int i=0;i<n;i++) cin >> ar[i];
    sort(ar,ar+n);
    ll i=n-1,a=0,b=0;
    for(;i>=1;i--)
    {
        if(ar[i]==ar[i-1])
        {
            a=ar[i];
            i-=2;
            break;
        }
    }
    for(;i>=1;i--)
    {
        if(ar[i]==ar[i-1])
        {
            b=ar[i];
            i--;
            break;
        }
    }
    cout << a*b << endl;
}