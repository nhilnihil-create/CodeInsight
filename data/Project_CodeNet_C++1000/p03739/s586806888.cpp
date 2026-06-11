#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long s1=0,s2=0,r1=0,r2=0,ans;
    for(int i=0;i<n;i++){
        s1+=a[i];
        if((i&1)&&s1<=0){
            r1=r1+1-s1;
            s1=1;
        }else if(!(i&1)&&s1>=0){
            r1=r1+s1+1;
            s1=-1;
        }

        s2+=a[i];
        if(!(i&1)&&s2<=0){
            r2=r2+1-s2;
            s2=1;
        }else if((i&1)&&s2>=0){
            r2=r2+s2+1;
            s2=-1;
        }
    }
    ans=min(r1,r2);
    cout<<ans<<endl;
    return 0;
}