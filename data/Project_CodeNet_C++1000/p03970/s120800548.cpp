#include<iostream>
char a[16], b[16] = {'C', 'O', 'D', 'E', 'F', 'E', 'S', 'T', 'I', 'V', 'A', 'L', '2', '0', '1', '6'};
int ans;
int main(void){
    std::cin >> a;
    for(int i = 0; i < 16; i ++){
        if(a[i] != b[i]) ans++;
    }
    std::cout << ans << "\r\n";  
}