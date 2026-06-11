#include <iostream>
using namespace std;
typedef long long  LL;
const int N = int(2e3) + 10;
LL a[N],b[N];
LL n,x;
int f(int i){
    if(i<=0) i+=n;
    return i;
}
int main(){
    scanf("%lld %lld",&n,&x);
    LL sum=0;
    for(int i=1;i<=n;i++) {cin>>a[i];sum+=a[i];b[i]=a[i];}
    for(int i=1;i<=n-1;i++){
        LL tmp=x*i;
        for(int j=1;j<=n;j++){
            b[j]=min(b[j],a[f(j-i)]);
            tmp+=b[j];
        }
        sum=min(sum,tmp);
    }
    cout<<sum<<endl;
}
