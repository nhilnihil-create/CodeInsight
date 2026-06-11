#include<bits/stdc++.h>
int main(){
    int h,w,k;std::cin>>h>>w>>k;
    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            if(i*j+(h-i)*(w-j)==k){
                std::cout<<"Yes"<<'\n';
                return 0;
            }
        }
    }
    std::cout<<"No"<<'\n';
}