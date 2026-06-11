#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#define F first  
#define S second  
  
using namespace std;  
  
typedef long long ll;  
  
ll n;  
pair<ll, ll> a[100005];  
ll ans;  
  
int main()  
{  
    scanf("%lld", &n);  
    for(ll i = 0; i < n; i++)  
    {  
        scanf("%lld", &a[i].F);  
        a[i].S = i;  
    }  
    sort(a, a + n);  
    for(ll i = 0; i < n; i++)  
    {  
        if(i % 2 != a[i].S % 2) ans++;  
    }  
    cout<<ans / 2<<endl;  
    return 0;  
}  

