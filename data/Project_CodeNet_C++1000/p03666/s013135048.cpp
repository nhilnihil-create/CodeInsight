#include <iostream>
#include <string>

int main()
{
    long long N, A, B, C, D;
    std::cin >> N >> A >> B >> C >> D;

    std::string out = "NO";
    for(int i=0; i<N; i++){
        long long l = C * i - D * (N-1-i);
        long long h = D * i - C * (N-1-i);
        if(l <= B-A && B-A <= h){
            out = "YES"; break;
        }
    }
    std::cout << out << std::endl;
}