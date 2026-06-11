#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    int A,B,C,D;
    cin>>A>>B>>C>>D;

    int Alice[105]={0}, Bob[105]={0};
    for(int i=A; i<B; i++) Alice[i]=1;
    for(int i=C; i<D; i++) Bob[i]=1;

    int ans=0;
    for(int i=0; i<100; i++) ans+=Alice[i]*Bob[i];

    cout<<ans<<endl;

    return 0;
}