#include <iostream>

using namespace std;
long long I,O,T,J,L,S,Z,ans,i;
int main()
{
    cin>>I>>O>>T>>J>>L>>S>>Z;
    for(i=0;i<=10;i++)
        if(i<=I&&i<=J&&i<=L)
          ans=max(ans,6LL*i+4LL*((I-i)/2)+4LL*((J-i)/2)+4LL*((L-i)/2));
    cout<<ans/2+1LL*O;
    return 0;
}
