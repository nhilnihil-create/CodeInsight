#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>

using ll = long long;

int main(){
    int a,b;
    std::cin >>a >> b;
    std::string ans = "Impossible";
    if((a+b)%3==0){
        ans = "Possible";
    }
    else if(a%3==0){
        ans = "Possible";
    }
    else if(b%3==0){
        ans = "Possible";
    }
    std::cout << ans << std::endl;
}