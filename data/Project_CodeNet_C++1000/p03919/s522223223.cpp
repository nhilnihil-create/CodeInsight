#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<array>
#include<math.h>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    int H, W;
    int ansH;
    char ansW;
    std::cin >> H >> W;
    string str;
    int A = 'A';
    for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> str;
            if (str == "snuke") {
                ansW = j+A;
                ansH = i+1;
            }
        }
    }
    std::cout << ansW << ansH << '\n';
    return 0;
}