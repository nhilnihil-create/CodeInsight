#include <bits/stdc++.h>
int n,i=1;
main(){
    std::cin>>n;
    for(;(i*i+i)/2<n;i++);
    for(;i>0;i--){
        if(n-i>=0){
            std::cout<<i<<'\n';
            n-=i;
        }
    }
}