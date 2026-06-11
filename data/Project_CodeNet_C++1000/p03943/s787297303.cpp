#include <iostream>
#include <cstdio>

using namespace std;


class Solution{
    
public:
    bool isPossible(int a, int b, int c){
        return a == b + c || b == a + c || c == a + b;
    }
};

int main() {
    
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%s\n", Solution().isPossible(a, b, c) ? "Yes" : "No");
    
    return 0;
}
