#include <iostream>
using namespace std;
typedef long long ll;
ll n,k;
ll f(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return 0;
    ll tmp=((a-1)/b)*2+((a%b)==0);
    //cout<<a<<b<<tmp<<endl;
    return f(b,a%b)+tmp*b;
}
int main(void){
    cin>>n>>k;
    cout<<f(n-k,k)+n<<endl;
}
