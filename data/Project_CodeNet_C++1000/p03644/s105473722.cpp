#include <iostream>
using namespace std;

int main() {
    int n;cin>>n;
    int ans=1;
    int cc1=0;
    for(int i=1;i<=n;++i){
        int tmp = i;
        int cc = 0;
        while(tmp>0){
            if(tmp%2==0){
                ++cc;
                tmp/=2;
            }
            else break;
        }
        if(cc>cc1){
            cc1=cc;
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}