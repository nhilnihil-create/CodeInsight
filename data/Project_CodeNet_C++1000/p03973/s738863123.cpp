#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long int ll;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll last=1;
    ll ans=a[0]-1;
    for(int i=1;i<n;i++){
        if(a[i]==(last+1)){
            last++;
        }
        else if(a[i]<last+1){
            continue;
        }
        else if(a[i]%(last+1)==0){
            a[i]-=(last+2);
            ans++;
            ans+=a[i]/(last+1);
            last=max(last,a[i]%(last+1));
        }
        else{
            ans+=a[i]/(last+1);
            last=max(last,a[i]%(last+1));
        }
    }
    cout << ans << endl;
}