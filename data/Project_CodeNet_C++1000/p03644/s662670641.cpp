#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int b[1000];
int main(void){
    int n; cin>>n;
    b[0]=1;
    for(int i=1;i<10;i++){
        b[i]=b[i-1]*2;
    }
    for(int i=0;i<10;i++){
        if(b[i]>n){
            cout<<b[i-1]<<endl;
            return 0;
        }
    }
    
    
}
