#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++){
        std::cin >> A.at(i);
    }

    int odds = 0;
    for(int i = 0; i < N; i++){
        if(A.at(i) % 2 == 1) odds++;
    }

    if(odds % 2 == 1){
        std::cout << "NO" << std::endl;
    }else{
        std::cout << "YES" << std::endl;
    }
    
}
