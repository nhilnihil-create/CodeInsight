#include <iostream>

using namespace std;
const long long MAXN = 2e5+5;
long long arr[MAXN];
long long pref[MAXN];
long long ans=1e18;
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
        pref[i] = pref[i-1]+arr[i];
    }
    long long suff = 0;
    for(long long i=n;i>=2;i--){
        suff+=arr[i];
        ans = min(ans,abs(suff-pref[i-1]));
    }
    cout<<ans<<endl;
}
