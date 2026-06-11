#include<bits/stdc++.h>
using namespace std;

using ll=long long;
bool query(ll x){
    cout<<"? "<<x<<endl;
    char res;
    cin>>res;
    return res=='Y';
}

void answer(int n){
    cout<<"! "<<n<<endl;
    return;
}
int main(){
    ll ten=1;
    for(int k=0;k<=10;k++){
        if(!query(ten)){
            ll lb=ten/10;
            ll ub=ten;
            while(ub-lb>1){
                ll mid=(ub+lb)/2;
                if(!query(mid*10)){
                    lb=mid;
                }
                else{
                    ub=mid;
                }
            }
            answer(ub);
            return 0;
        }
        ten*=10;
        if(k==10){
            //ten keitou
            ten=1;
            for(int i=0;i<10;i++){
                if(query(2*ten)){
                    answer(ten);
                    return 0;
                }
                ten*=10;
            }
        }
    }
    return 0;
}