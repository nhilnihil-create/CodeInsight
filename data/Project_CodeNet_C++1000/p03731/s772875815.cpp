#include <iostream>
using namespace std;

int main() {
    int n;cin>>n;
    long long int t,a[n],s[n],ans=0;
    
    cin>>t>>a[0];
    for(int i=1;i<n;++i){
        cin>>a[i];
        s[i-1]=a[i]-a[i-1];
    }

    for(int i=0;i<n-1;++i){
        if(s[i]<=t)ans+=s[i];
        else ans+=t;
    }
    ans+=t;
    
    cout<<ans<<endl;

	return 0;
}