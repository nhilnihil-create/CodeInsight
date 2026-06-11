#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> color(9, 0);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] < 400) color[0]++;
        else if(a[i] < 800) color[1]++;
        else if(a[i] < 1200) color[2]++;
        else if(a[i] < 1600) color[3]++;
        else if(a[i] < 2000) color[4]++;
        else if(a[i] < 2400) color[5]++;
        else if(a[i] < 2800) color[6]++;
        else if(a[i] < 3200) color[7]++;
        else color[8]++;
    }

    int type = 0;
    for(int i = 0; i < 8; i++){
        type += (color[i] != 0);
    }

    std::cout << std::max(type, 1) << " " << type + color[8] << std::endl;
    return 0;
}
