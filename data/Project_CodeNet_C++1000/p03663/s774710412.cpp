#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ques(ll n){
    cout<<"? "<<n<<endl;
    string ans;
    cin>>ans;
    return (ans=="Y");
}

int main(void){
    int d=1e9;
    if(ques(d)){
        while(d>1 && ques(d-1)) d/=10;
        cout<<"! "<<d<<endl;
    }else{
        while(d/=10,!ques(d));
        ll l=d,r=d*10;
        while(l+1<r){
            ll m=(l+r)/2;
            if(ques(m*10)) r=m;
            else l=m; 
        }
        cout<<"! "<<r<<endl;
    }
    return 0;
}
