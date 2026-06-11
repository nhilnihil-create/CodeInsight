#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    int n,a[100000];
    ll s=0,m,k=1e9+7,l=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
        k=min(k, (ll)a[i]);
    }
    m=(ll)n*(n+1)/2;
    if(s%m>0){
        cout<<"NO"<<endl;
        return 0;
    }else{
        s=s/m;
        for(int i=0;i<n;i++){
            if(a[i]>=a[(i+1)%n]){
                ll y=(a[i]-a[(i+1)%n]+s);
                if(y%n==0){
                    l+=y/n;
                }else{
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
        if(l==s){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
}
