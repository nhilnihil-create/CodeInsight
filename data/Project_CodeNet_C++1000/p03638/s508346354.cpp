#include <iostream>
#include <vector>

void print(std::vector<int> readVec){
    int sz = readVec.size();
    for(int i = 0; i < sz; ++i){
        std::cout << readVec.at(i);
        if(sz - 1 == i){
            std::cout << std::endl;
        }else{
            std::cout << " ";
        }
    }
}

int main(){
    int h, w, n;
    std::cin >> h >> w >> n;
    
    std::vector<int> ref;
    for(int i = 0; i < n; ++i){
        int val;
        std::cin >> val;

        for(int j = 0; j < val; ++j){
            ref.push_back(i + 1);
        }
    }

    std::vector<std::vector<int>> ans;
    for(int i = 0; i < h; ++i){
        if(0 == i){
            ans.push_back(std::vector<int>(ref.begin(), ref.begin() + w));
        }else{
            std::vector<int> buf(ref.begin() + i * w, ref.begin() + (i + 1) * w);
            if(ans.at(i - 1).at(w - 1) == buf.at(0)){
                std::reverse(buf.begin(), buf.end());
            }
            ans.push_back(buf);
        }
    }

    for(int i = 0; i < h; ++i){
        print(ans.at(i));
    }    

    return 0;
}