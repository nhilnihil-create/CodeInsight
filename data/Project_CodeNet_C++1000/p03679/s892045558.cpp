#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int x,a,b; cin>>x>>a>>b;
    if(a>=b){
        cout<<"delicious"<<endl;
    }else if(x+a>=b){
        cout<<"safe"<<endl;
    }else{
        cout<<"dangerous"<<endl;
    }
    
}
