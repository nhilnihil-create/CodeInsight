#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll I,O,T,J,L,S,Z,ans=0;
int main()
{
    cin>>I>>O>>T>>J>>L>>S>>Z;
    ans+=O;
    if(!I || !J || !L)ans+=I/2*2+J/2*2+L/2*2;
    else{
        ans+=I+J+L;
        if((I&1)==(J&1) && (J&1)==(L&1));
        else --ans;
    }
    cout<<ans<<endl;
    return 0;
}
