#include<iostream>
using namespace std;
#define ll long long

int main(){
    int N;cin>>N;
    ll nt=1,na=1;
    ll t,a;
    for(int i=0;i<N;i++){
        cin>>t>>a;    
        if(nt<=t&&na<=a){
            nt=t;
            na=a;
        }
        else{
            ll s=max((nt+t-1)/t,(na+a-1)/a);
            nt=t*s;
            na=a*s;
        }
    }
    cout<<nt+na<<endl;
    return 0;
}