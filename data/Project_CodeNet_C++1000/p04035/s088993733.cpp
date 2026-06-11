#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, l;
    std::cin >> n >> l;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    
    for (int i = 0; i < n-1; i++){
        
        if (a[i] + a[i+1] >= l){
            
            std::cout << "Possible" << std::endl;
            
            for (int j = 0; j < i; j++) std::cout << j+1 << std::endl;
            for (int j = n-2; j >= i+1; j--) std::cout << j+1 << std::endl;
            
            std::cout << i+1 << std::endl;
            return 0;
        }
    }
    
    std::cout << "Impossible" << std::endl;
    return 0;
}
