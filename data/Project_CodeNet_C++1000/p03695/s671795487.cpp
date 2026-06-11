#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long N;
    std::cin >> N;
    long a[100]={};
    for(long i=0; i<N; i++){
        std::cin >> a[i];
    }
    bool rating[8]={};
    long max=0;
    for(long i=0; i<N; i++){
        if(3200<=a[i]){
            max++;
        }else{
            rating[a[i]/400]=1;
        }
    }
    long color=0;
    for(long i=0; i<8; i++){
        color+=rating[i];
    }
    long ans1,ans2;
    if(color==0){
        ans1=1;
    }else{
        ans1=color;
    }
    ans2=color+max;
    std::cout << ans1 << " " << ans2 << std::endl;
    return 0;
}