#include<iostream>
using namespace std;
const int mod=1e9+7;
int main(){
    int n;
    cin>>n;
    int power=1;
    long long int finpower=1;
    for(int i=0;i<n;i++){
        finpower*=power;
        finpower=finpower%mod;
        power++;
    }
    cout<<finpower;
}