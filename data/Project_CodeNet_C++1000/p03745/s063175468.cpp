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

    int num = 1;
    int a = A.at(0);
    int diff = 0;
    for(int i = 1; i < N; i++){
        int nd = A.at(i) - a;
        a = A.at(i);
        if(nd == 0 || diff == 0 || (nd < 0 && diff < 0) || (nd > 0 && diff > 0)){
            if(nd != 0){
                diff = nd;
            }
        }else{
            num++; // new seriese
            diff = 0;
        }
    }
    std::cout << num << std::endl;
    
}
