#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
int main(void){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(0,min(b,d)-max(a,c))<<endl;
}