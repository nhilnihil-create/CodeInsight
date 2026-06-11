#include <iostream>
#include <cstdlib>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c ;
    std::cin >> a >> b >> c ;
    if(a%2==0&&a==b&&b==c) {
        std::cout << "-1" << std::endl;
        std::exit(0); 
    }
    
    int tempA,tempB,tempC;
    int count=0;

    
    while (a%2==0 && b%2==0 && c%2==0 && count < 50){
        tempA=a;
        tempB=b;
        tempC=c;
        a=(tempB+tempC)/2;
        b=(tempA+tempC)/2;
        c=(tempA+tempB)/2;
        count+=1;
    }
    if (count == 50 ) {
        std::cout << "-1" << std::endl;
    }
    else {
        std::cout << count << std::endl;

    }

    return 0;
}
