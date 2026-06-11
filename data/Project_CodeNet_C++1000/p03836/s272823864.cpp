#include<iostream>
#include<vector>
#include<string>

int main(){
    int x[2], y[2];
    std::cin >> x[0] >> y[0] >> x[1] >> y[1];
    std::string out = std::string(y[1] - y[0], 'U') + std::string(x[1] - x[0], 'R');
    out += std::string(y[1] - y[0], 'D') + std::string(x[1] - x[0], 'L');
    out += "L";
    out += std::string(y[1] - y[0] + 1, 'U');
    out += std::string(x[1] - x[0] + 1, 'R');
    out += "D";
    out += "R";
    out += std::string(y[1] - y[0] + 1, 'D');
    out += std::string(x[1] - x[0] + 1, 'L');
    out += "U";
    std::cout << out << std::endl;
    return 0;
}
