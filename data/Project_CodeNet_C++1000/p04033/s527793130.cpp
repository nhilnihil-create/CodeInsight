//Range Product

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end()
struct edge{int to;ll cost;};
const int inf = 2147483647;

int main (){
    ll a,b;cin>>a>>b;
    if(a*b<=0){cout<<"Zero"<<endl;return 0;}
    if(a>0&&b>0){cout<<"Positive"<<endl;return 0;}
    if((b-a)%2==0){cout<<"Negative"<<endl;return 0;}
    else {cout<<"Positive"<<endl;return 0;}
    return 0;
}