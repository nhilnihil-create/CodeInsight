#include<iostream>
int n,i;main(){std::cin>>n;while((i*i+i)/2<n)i++;while(i){if(n-i>=0)std::cout<<i<<'\n',n-=i;i--;}}