#include <iostream>
#include <cstdio>

using namespace std;


class Solution{

public:
    int area(int a, int b, int h){
        return (a + b) * h / 2;
    }
};

int main() {
    
    int a, b, h;
    scanf("%d%d%d", &a, &b, &h);
    printf("%d\n", Solution().area(a, b, h));
    
    return 0;
}
