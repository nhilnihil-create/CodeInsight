#include <iostream>
#include <vector>
#include <algorithm>

constexpr int INF = 1145141919;


int main(){
	std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N, A, B;
    std::cin >> N >> A >> B;

    std::string S;
    std::cin >> S;

    int sanka_all    = 0;
    int sanka_kaigai = 0;
    for(int i=0; i<N; i++){
        if( S[i] == 'a' ){
            if( sanka_all<A+B ){
                sanka_all++;
                std::cout << "Yes" << '\n';
            }else{
                std::cout << "No" << '\n';
            }
        }else if( S[i] == 'b' ){
            if( sanka_all<A+B && sanka_kaigai<B ){
                sanka_kaigai++;
                sanka_all++;
                std::cout << "Yes" << '\n';
            }else{
                std::cout << "No" << '\n';
            }
        }else{
            std::cout << "No" << '\n';
        }
    }

    return 0;
}
