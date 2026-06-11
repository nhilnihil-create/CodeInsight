#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main(){
    long long a,n,num,ans=100000000000;
    cin>>n;
    for (int i=1;i<=sqrt(n);i++){
        if (n%i==0){
            a=n/i;
            num=to_string(a).size();
            ans=min(ans,num);
        }
    }
    cout<<ans<<endl;
}
