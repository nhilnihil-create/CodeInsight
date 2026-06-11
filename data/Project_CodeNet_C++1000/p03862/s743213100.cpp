#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define ve vector
#define umap unordered_map

const int MxN=1e5;
int a[MxN];

int main() {
    ll n, x;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++) {
        if(a[i]+a[i-1] >x) {
            ans+= (a[i]+a[i-1]-x);
            a[i] -= (a[i]+a[i-1]-x);
        }
    }
    cout<<ans<<endl;
    
}