#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (long long)((a).size())

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    
    ll x,i,j;
    cin>>x;
    i = 1;
    while((i*(i+1))/2 < x) i++;
    cout<<i;
}
