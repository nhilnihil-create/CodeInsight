#include <iostream>
using namespace std;
int main(){
    int k,n;
    cin >> n >> k;
    long long a[n];
    long long ans = 0;
    long long p,m;
    p = m = 0;
    for(int i = 0;i<k;i++){
        cin >> a[i];
        if(a[i]>=0){
            ans+=a[i];
            p+=a[i];
        }
        else m+=abs(a[i]);
    }
    long long sac = min(p,m);
    for(int i = k;i<n;i++){
        cin >> a[i];
        if(a[i-k]>=0)p-=a[i-k];
        else m-=abs(a[i-k]);
        if(a[i]>=0){
            ans+=a[i];
            p+=a[i];
        }
        else m+=abs(a[i]);
        sac = min(sac,min(p,m));        
    }
    cout << ans-sac << endl;
}