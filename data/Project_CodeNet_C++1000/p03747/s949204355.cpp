#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[2000001];
int n,l,t;
signed main(){
    scanf("%lld%lld%lld",&n,&l,&t);
    int tmp=1;
    for(int i=1;i<=n;++i){
        int x,w;
        scanf("%lld%lld",&x,&w);
        if(w==1){
            ans[i]=(x+t)%l;
            tmp+=(x+t)/l;
        }
        else {
            ans[i]=(x-t)%l;
            tmp+=(x-t)/l;
            if(ans[i]<0)ans[i]+=l,tmp--;
        }
    }
    //cout<<tmp<<endl;
    sort(ans+1,ans+1+n);
    tmp=((tmp%n)+n)%n;
    if(tmp==0)tmp=n;
    for(int i=tmp;i<=n;++i)printf("%lld\n",ans[i]);
    for(int i=1;i<tmp;++i)printf("%lld\n",ans[i]);
}
/*
3 3 8
0 1
1 2
2 1
*/
