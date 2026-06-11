#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2003,INF=10000;

int main(){
    
    ll I,O,T,J,L,S,Z;cin>>I>>O>>T>>J>>L>>S>>Z;
    ll ans=0;
    int cnt=0;
    ans+=O;
    if(I%2==1) cnt++;
    if(J%2==1) cnt++;
    if(L%2==1) cnt++;
    if(I==0||J==0||L==0) cnt=-1;
    if(cnt==3){
        ans+=(I/2)*2+(J/2)*2+(L/2)*2;
        ans+=3;
    }else if(cnt==-1||cnt==1||cnt==0){
        ans+=(I/2)*2+(J/2)*2+(L/2)*2;
    }else if(cnt==2){
        ans+=(I/2)*2+(J/2)*2+(L/2)*2;
        ans++;
    }
    cout<<ans<<endl;
}
