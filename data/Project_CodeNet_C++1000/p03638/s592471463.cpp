#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int H, W;
    int N;

    std::cin >> H >> W >> N;
    std::vector<int> a(N);
    std::vector<std::vector<int>> m(H, std::vector<int>(W));

    for(int i = 0; i < N; i++){
        std::cin >> a.at(i);
    }

    int h = 0, w = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < a.at(i); j++){
            m.at(h).at(w) = (i+1);
            w++;
            if(w == W){
                w = 0;
                h++;
            }
        }
    }
    bool flip = false;
    for(int i = 0; i < H; i++){
        std::string sep = "";
        if(flip){
            for(int j = W-1; j >= 0; j--){
                std::cout << sep << m.at(i).at(j);
                sep = " ";
            }
        }else{
            for(int j = 0; j < W; j++){
                std::cout << sep << m.at(i).at(j);
                sep = " ";
            }
        }
        std::cout << std::endl;
        flip = !flip;
    }
    
}
