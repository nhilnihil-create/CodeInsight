#include<iostream>
int N;
int main(){
    std::cin>>N;
    int sum=0;
    int now=1;
    while(sum<N){
        sum+=now;
        now++;
    }
    for(int i=1;i<now;i++){
        if(i==sum-N)continue;
        std::cout<<i<<std::endl;
    }
    return 0;
}