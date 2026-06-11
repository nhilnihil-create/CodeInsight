#include<iostream>
#define LL long long
LL K;
LL A[50];
int main(){
    std::cin>>K;
    std::cout<<50<<std::endl;
    for(int i=0;i<50;i++){
        A[i]=49+(K/50);
    }
    for(int i=0;i<K%50;i++){
        A[i]+=50;
        A[i]-=K%50-1;
    }
    for(int i=K%50;i<50;i++){
        A[i]-=K%50;
    }
    for(int i=0;i<50;i++){
        std::cout<<A[i];
        if(i<49)std::cout<<" ";
        else std::cout<<std::endl;
    }
    return 0;
}