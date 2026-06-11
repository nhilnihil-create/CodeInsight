#include <iostream>
using namespace std;

int main(void){
    int n,t,ans=0;
    cin>>n>>t;
    int t1=0,t2=0;
    for(int i=0;i<n;i++){
        t1 = t2;
        cin>>t2;
        ans += min(t2-t1,t);
    }
    ans += t;
    cout<<ans<<endl;
}