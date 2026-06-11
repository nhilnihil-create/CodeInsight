#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <deque>


int main()
{
    long N;
    std::cin >> N;
    std::vector<long> a;
    for(long i=0; i<N; i++){
        long temp;
        std::cin >> temp;
        a.push_back(temp);
    }
    std::sort(a.begin(),a.end());

    bool flag=true;
    for(long i=N-1; i>1; i-=2){
        if(i!=0){
            if(a[i]!=i || a[i-1]!=i){
                flag=false;
            }
        }else{
            if(a[0]!=0){
                flag=false;
            }
        }
    }
    if(!flag){
        std::cout << 0 << std::endl;
    }else{
        long result=1;
        for(long i=0; i<N/2; i++){
            result=result*2;
            result=result%(1000000000+7);
        }
        std::cout << result << std::endl;
    }
    return 0;
}