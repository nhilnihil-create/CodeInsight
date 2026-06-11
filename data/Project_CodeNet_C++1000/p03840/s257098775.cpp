#include<bits/stdc++.h>
int main(){
    long long _,a,b,c,d;
    std::cin>>a>>b>>_>>c>>d>>_>>_;
    long long ans=b+2*(a/2+c/2+d/2)+3*(a%2&&c%2&&d%2);
    if(a--&&c--&&d--){
        long long x=b+2*(a/2+c/2+d/2)+3;
        if(ans<x)ans=x;
    }
    std::cout<<ans<<std::endl;
}
