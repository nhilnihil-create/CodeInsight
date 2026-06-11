#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll K;
int main(){
    cin>>K;
    int n=50;
    printf("%d\n",n);
    ll a=K/(ll)n; ll b=K%(ll)n;
    int cnt=0;
    for(int i=1;i<=(int)b;++i){
        ++cnt;
        cout<<49ll+a+((ll)n-(b-1ll))<<(cnt==n ? '\n' : ' ');
    }
    for(int i=1;i<=n-(int)b;++i){
        ++cnt;
        cout<<49ll+a-b<<(cnt==n ? '\n' : ' ');
    }
    return 0;
}