#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main(){
    ll X=0,t=0;
    cin>>X>>t;
    if (X-t>0){
        cout<<X-t<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}
