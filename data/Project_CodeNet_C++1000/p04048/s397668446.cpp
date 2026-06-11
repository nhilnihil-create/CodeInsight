#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define ll long long
const int maxm=2e6+5;
int n,x;
int cal(int a,int b){
    if(!a)return 0;
    int ans=0;
    ans+=cal(b%a,a);
    ans+=b/a*2*a;
    return ans;
}
signed main(){
    cin>>n>>x;
    int a=x,b=n-x;
    if(a>b)swap(a,b);
    int ans=cal(a,b)+n;//外面两条边的长度=x+(n-x)=n
    ans-=__gcd(n,x);
    cout<<ans<<endl;
    return 0;
}
