#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    ll a,b; cin>>a>>b;
    if(a>0){
        cout<<"Positive"<<endl;
    }else if(a==0){
        cout<<"Zero"<<endl;
    }else if(a<0){
        if(b>=0){
            cout<<"Zero"<<endl;
        }else{
            if((b-a)%2==1){
                cout<<"Positive"<<endl;
            }else{
                cout<<"Negative"<<endl;
            }
        }
    }
    
}
