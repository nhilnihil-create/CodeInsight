#include <bits/stdc++.h>
int n,i=1;
main(){
    std::cin>>n;
    while((i*i+i)/2<n)i++;
    while(i){
        if(n-i>=0){
            std::cout<<i<<'\n';
            n-=i;
        }
        i--;
    }
}