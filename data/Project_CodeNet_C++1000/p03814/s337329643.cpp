#include <iostream>

int main(void){
    int ans=0, l, r;
    bool flg=false;
    std::string s;
    std::cin >> s;

    for (int i=0; i<s.size(); ++i){
        char a = s.at(i);
        if (a == 'A' && not(flg)){
            flg = true;
            l = i;
        } else if (a == 'Z' && flg){
            r = i;
            ans = r - l + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
