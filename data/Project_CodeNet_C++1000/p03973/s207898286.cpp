#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    int n;
    ll m=0, p=1;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(a>p){
            m+=(a-1)/p;
            if(p==1)p++;
        }else if(a==p)p++;
    }
    cout<<m<<endl;
}
