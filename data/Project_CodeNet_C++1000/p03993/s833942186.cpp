#include <bits/stdc++.h>
#define ll long long
using namespace std;

//GCD,LCM
ll gcd(ll a, ll b){ return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){ return a/gcd(a,b)*b;}

int main()
{
    int N,A[100010]={},ans=0;

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }

    for(int i=1;i<=N;i++){
        if(i==A[A[i]])ans++;
    }

    cout<<ans/2<<endl;

    return 0;
}