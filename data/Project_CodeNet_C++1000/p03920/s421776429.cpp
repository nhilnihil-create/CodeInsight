#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n;
    cin>>n;
    int max=0;
    int sa=0;
    for(int i=0;i<n+2;i++){
        if((i*(i+1))/2>=n){
            max=i;
            sa=(i*(i+1))/2-n;
            break;
        }
    }
    for(int i=1;i<max+1;i++){
        if(i!=sa){
            cout<<i<<endl;
        }
    }
}