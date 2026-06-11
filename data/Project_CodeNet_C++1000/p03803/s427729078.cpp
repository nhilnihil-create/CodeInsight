#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int a,b; cin>>a>>b;
    if(a==1) a=14;
    if(b==1) b=14;
    if(a<b){
        cout<<"Bob"<<endl;
    }else if(a>b){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Draw"<<endl;
    }
    
}
