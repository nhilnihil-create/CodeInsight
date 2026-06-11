#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
long long buf[100001]={};
int main(){
    int n;
    scanf("%d",&n);
    std::vector<std::pair<long long,int>> vp;
    vp.push_back({0,0});
    for(int i=1;i<=n;i++){
        long long a;
        scanf("%lld",&a);
        vp.push_back({a,i});
    }
    std::sort(vp.begin(),vp.end(),std::greater<std::pair<long long,int>>());
    int mink=1000000;
    for(int i=0;i<n;i++){
        if(mink>vp[i].second)mink=vp[i].second;
        buf[mink]+=(vp[i].first-vp[i+1].first)*((long long)(i+1));
    }
    for(int i=1;i<=n;i++){
        printf("%lld\n",buf[i]);
    }
    return 0;
}