#include<bits/stdc++.h>
int main(){
    long long _,a,b,c,d;
    std::cin>>a>>b>>_>>c>>d>>_>>_;
    std::cout<<b+std::max(2*(a/2+c/2+d/2),(a&&c&&d)*(2*((a-1)/2+(c-1)/2+(d-1)/2)+3))<<std::endl;
}
