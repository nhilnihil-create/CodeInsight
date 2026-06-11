#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a2, a4, a;
    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        if(tmp % 4 == 0){
            a4.push_back(tmp);
        }else if(tmp % 2 == 0){
            a2.push_back(tmp);
        }else{
            a.push_back(tmp);
        }
    }

    // 例外処理
    if(a.empty()){
        std::cout << "Yes" << std::endl;
        return 0;
    }

    // aの要素の横には必ず4をいれ最終的に4の倍数で終われるかどうか
    if(a.size() - 1 < a4.size()){
        std::cout << "Yes" << std::endl;
    }else{
        // 最後4でなくてももう無ければOK
        if(a2.size() == 0 && a.size() - 1 == a4.size()){
            std::cout << "Yes" << std::endl;
        }else{
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
