#include <iostream>
#include <vector>
#include <string>
#include <bitset>

int main()
{
    int N;
    std::cin >> N;
    std::string s;
    std::cin >> s;

    std::vector<bool> sheep(N);
    bool valid = false;
    for(int i=0; i<4; i++){
        std::bitset<2> bit(i);
        sheep[0] = bit[0]; sheep[1] = bit[1];

        for(int i=1; i<N-1; i++){
            bool b = (s[i]=='o');
            b ^= sheep[i];
            sheep[i+1] = sheep[i-1] ^ b;
        }

        // for(int i=0; i<N; i++){
        // if(sheep[i] == true) printf("S");
        // else printf("W");
        // }
        // printf("\n");

        bool b1 = (s[N-1]=='o');
        bool b2 = (s[0]=='o');
        b1 ^= sheep[N-1];
        b2 ^= sheep[0];
        if((sheep[0]^sheep[N-2]) == b1 && (sheep[N-1]^sheep[1]) == b2){
            valid = true; break;
        }
    }

    if(valid == false){printf("-1\n"); return 0;}
    for(int i=0; i<N; i++){
        if(sheep[i] == true) printf("S");
        else printf("W");
    }
    printf("\n");
}