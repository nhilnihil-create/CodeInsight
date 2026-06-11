#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>

const long INF = (1l << 30);
const long LINF = (1l << 60);

long h, w;
std::string s;

int main(){
    scanf("%ld%ld", &h, &w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            std::cin >> s;
            if(s == "snuke"){
                printf("%c%d\n", (char)('A'+j), i+1);
            }
        }
    }
    return 0;
}
