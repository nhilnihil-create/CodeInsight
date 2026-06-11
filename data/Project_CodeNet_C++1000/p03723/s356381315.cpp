#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

constexpr int INFI = 1145141919;

int main(){
	std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    long long A, B, C;
    std::cin >> A >> B >> C;

    //各々が貰うのは別の人の半分
    if((A==B && B==C)&&(A%2==0 && B%2==0 && C%2==0)){
        std::cout << -1;
    }else{
        long long count=0;
        while(A%2==0 && B%2==0 && C%2==0){
            count++;
            long long a, b, c;
            a = B/2 + C/2;
            b = A/2 + C/2;
            c = A/2 + B/2;
            A = a; B = b; C = c;
        }
        std::cout << count;
    }

    return 0;
}
