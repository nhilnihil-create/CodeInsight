#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll A=a*b;
    ll B=c*d;
    if(A>B)
    {
        cout<<A<<endl;
    }
    else
    {
        cout<<B<<endl;
    }

  return 0;
}

