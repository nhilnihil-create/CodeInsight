#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
using namespace std;
using ll=int64_t;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
int gcd(int a,int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
int main(){
    int k,s;
    cin>>k>>s;
    int ans=0;
    for(int x=0;k>=x;++x){
        for(int y=0;k>=y;++y){
            int z=s-x-y;
            if(z>=0&&z<=k)
            ++ans;
        }
    }
    cout<<ans<<endl;
}
