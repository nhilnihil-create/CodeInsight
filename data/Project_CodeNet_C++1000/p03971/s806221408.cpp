#include <iostream>
#include <string>

int main(){
    int n = 0;
    int a = 0;
    int b = 0;
    std::string s;
    int pass = 0;
    int passb = 1;

    std::cin >> n >> a >> b;
    std::cin >> s;

    for(int i = 0; i < n; i++){
        if(s[i] == 'a' && pass < a + b){
            std::cout << "Yes" << std::endl;
            pass++;
        }
        else if(s[i] == 'b' && pass < a + b && passb <= b){
            std::cout << "Yes" << std::endl;
            pass++;
            passb++;
        }
        else{
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}