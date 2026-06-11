#include <iostream>

using namespace std;

class Solution{

public:
    int numOfColors(int a, int b, int c){

        if(a == b && b == c) return 1;
        if(a == b || a == c || b == c) return 2;
        return 3;
    }
};


int main() {

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", Solution().numOfColors(a, b, c));

    return 0;
}