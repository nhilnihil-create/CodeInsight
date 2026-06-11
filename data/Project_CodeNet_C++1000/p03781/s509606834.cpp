#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
    int x; cin>>x;
    long sum=0,ans;
    rep(i,x+1){
        sum+=i;
        if(x<=sum) {ans=i;break;}
    }
    cout<<ans<<endl;
    return 0;
}
