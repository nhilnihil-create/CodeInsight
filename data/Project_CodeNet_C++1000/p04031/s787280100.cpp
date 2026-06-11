#include <iostream>
using namespace std;
 
int main(void){
    int n,asum=0;
    cin>>n;
    int a[n] = {};
    for(int i=0;i<n;i++){
        cin>>a[i];
        asum += a[i];
    }
    int y;
    if(asum>0) y = ( asum + n/2.0)/n;
    else y = ( asum - n/2)/n;
    int ans = 0;
    for(int i=0;i<n;i++) ans += (a[i]-y)*(a[i]-y);
    cout<<ans<<endl;
 
}
