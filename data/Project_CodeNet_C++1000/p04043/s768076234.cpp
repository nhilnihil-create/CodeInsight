#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


class Solution{

public:
    bool isHaiku(vector<int>& lines){

        sort(lines.begin(), lines.end());
        return lines[0] == 5 && lines[1] == 5 && lines[2] == 7;
    }
};

int main() {

    vector<int> lines(3);
    for(int i = 0; i < 3; i ++)
        scanf("%d", &lines[i]);

    printf("%s\n", Solution().isHaiku(lines) ? "YES" : "NO");

    return 0;
}
