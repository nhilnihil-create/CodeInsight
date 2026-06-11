#include <iostream>
using namespace std;
int main(void){
    int n,t[100000],a[100000],u=0,b;
    long long q=1,p=1e9+7;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i];
        if(i>0){
            if(t[i]>t[i-1]){
                u=i;
            }
        }
    }
    b=n-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0&&b==n-1){
            if(a[i]<a[i-1]){
                b=i-1;
                if(b<u){
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
    }
    if(t[u]!=a[b]){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<n-1;i++){
        if(i<u&&t[i]==t[i-1]){
            q=(q*t[i])%p;
        }else if(i>u&&a[i]==a[i+1]){
            q=(q*a[i])%p;
        }
    }
    cout<<q<<endl;
}
