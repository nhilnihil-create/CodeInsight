#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define ll  long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<ll,ll>
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define what_is(x) cerr << #x << " is " << x << endl;
int main()
{
    io;
    int n;
    cin >> n;
    int A[n],B[n];
    for(int i=0;i<n;i++)
    {
        cin >> A[i] >> B[i];
    }
    ll int one=1,two=1,mlt;
    for(int i=0;i<n;i++)
    {
        mlt=max((one+A[i]-1)/A[i],(two+B[i]-1)/B[i]);
        while(one>A[i]*mlt||two>B[i]*mlt)
        mlt++;
        one = A[i]*mlt;
        two = B[i]*mlt;
    }
    cout << one+two ;
}