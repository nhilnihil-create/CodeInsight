//*Here I go out to sea again
//*The sunshine fills my hair
//*And dreams hang in the air

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    if(n<=k){
      cout<<n*a<<"\n";
    }
    else{
      cout<<k*a+(n-k)*b<<"\n";
    }

    return 0;
}
