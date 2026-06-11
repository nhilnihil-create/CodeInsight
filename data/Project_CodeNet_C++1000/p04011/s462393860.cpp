#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N,K,X,Y;
    std::cin >> N >> K >> X >> Y;
    int fee = -1;
    if(N >= K){
        fee = K * X + (N - K) * Y;
    } else{
        fee = N * X;
    }
    std::cout << fee << '\n';    
    return 0;
}
