#include<iostream>
#include<vector>
#include<string>
#include<list>

int main(){
    int n;
    std::cin >> n;
    std::list<int> out;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        if(i % 2 == 0){
            out.push_back(a);
        }else{
            out.push_front(a);
        }
    }

    std::size_t size = out.size();
    // 偶数は頭から、奇数は後ろから読む
    if(size % 2 != 0){
        auto iter = out.end();
        while(iter != out.begin()){
            iter--;
            std::cout << *iter << " ";
        }
    }else{
        auto iter = out.begin();
        while(iter != out.end()){
            std::cout << *iter << " ";
            iter++;
        }
    }

    std::cout << std::endl;

    return 0;
}
