#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a,b,c;
int main(void){
    cin>>a>>b>>c;
    a=a%b;
    int A=a;
    while(true){
        A=(A+a)%b;
        if(A==c){
            cout<<"YES"<<endl;
            return 0;
        }
        if(A==a){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    
}
