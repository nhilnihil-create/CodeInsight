#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const ll INF=1e18;

int main(){
    ll h,w;cin>>h>>w;
    ll m=INF;
    ll  a,b,c;
    for(ll i=0;i<h;i++){
        a=w*i;
        b=(w/2)*(h-i);
        c=w*h-a-b;
        m=min(m,max(max(a,b),c)-min(min(a,b),c));

        b=w*((h-i)/2);
        c=w*h-a-b;
        m=min(m,max(max(a,b),c)-min(min(a,b),c));
    }
    for(ll j=0;j<w;j++){
        a=h*j;
        b=(h/2)*(w-j);
        c=w*h-a-b;
        m=min(m,max(max(a,b),c)-min(min(a,b),c));

        b=h*((w-j)/2);
        c=w*h-a-b;
        m=min(m,max(max(a,b),c)-min(min(a,b),c));
    }
    cout<<m<<endl;
    return 0;
}