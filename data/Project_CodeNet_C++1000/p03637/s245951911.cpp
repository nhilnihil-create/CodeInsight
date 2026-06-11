#include <iostream>
#include <vector>

int main(int argc, char **argv){
    int N;
    std::cin >> N;
    std::vector<int> a(N);

    int quad = 0;
    int odd = 0;
    int bi = 0;
    for(int i = 0; i < N; i++){
        std::cin >> a.at(i);
        if(a.at(i) % 4 != 0 && a.at(i) % 2 == 0) bi++;
        if(a.at(i) % 4 == 0) quad++;
        if(a.at(i) % 2 == 1) odd++;
    }
    bool flag = false;
    if(odd == 0){
        flag = true;
    }else if(bi > 0){
        if(odd <= quad) flag = true;
    }else{
        if(odd-1 <= quad) flag = true;
    }
    
    if(flag)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
}
