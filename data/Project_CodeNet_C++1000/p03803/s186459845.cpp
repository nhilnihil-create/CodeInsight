#include<bits/stdc++.h>
typedef long long int ll;
#define optimization() ios_base::sync_with_stdio(0);
#define FOR(V,lim) for(ll V=0;V<lim;V++)
#define endl '\n'
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a==b)
        cout<<"Draw"<<endl;
    else if((a==1 || a>b) && b>1)
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;
return 0;
}
//Vanquisher_10
