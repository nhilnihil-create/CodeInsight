#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long I,O,T,J,L,S,Z;
    cin>>I>>O>>T>>J>>L>>S>>Z;
    
    long long sum=O;
    if(I&&J&&L){
        sum+=max((I/2+J/2+L/2)*2,3LL+((I-1)/2+(J-1)/2+(L-1)/2)*2);
    }else sum+=(I/2+J/2+L/2)*2;
    cout<<sum<<endl;
}
