#include <iostream>

int main(void){
    int n, a, b, cnt=0, cnt_f=0;
    std::string s, ans="";
    std::cin >> n >> a >> b >> s;

    for(char c: s){
        if (c == 'c'){
            ans = "No";
        } else if (c == 'a'){
            if (a + b > cnt){
                ans = "Yes";
                ++cnt;
            } else {
                ans = "No";
            }
        } else {
            if (a + b > cnt && b > cnt_f){
                ans = "Yes";
                ++cnt;
                ++cnt_f;
            } else {
                ans = "No";
            }
        }
        std::cout << ans << std::endl;
    }

    return 0;
}