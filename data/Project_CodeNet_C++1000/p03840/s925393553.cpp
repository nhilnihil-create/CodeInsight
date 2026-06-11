#include<bits/stdc++.h>
using namespace std;
int I,O,T,J,L,S,Z;
int main() {
    cin>>I>>O>>T>>J>>L>>S>>Z;
    if(I&&J&&L) printf("%lld\n",O+max(2ll*(I/2+J/2+L/2),3ll+2ll*((I-1)/2+(J-1)/2+(L-1)/2)));
    else printf("%lld\n",O+2ll*(I/2+J/2+L/2));
    return 0;
}
