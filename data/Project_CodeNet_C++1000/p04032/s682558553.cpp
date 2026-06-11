#include <iostream>
#include <string>

using namespace std;


class Solution{

public:
    pair<int, int> unbalanced(const string& s){

        for(int i = 0; i + 1 < s.size(); i ++)
            if(s[i] == s[i + 1]) return {i + 1, i + 2};

        for(int i = 0; i + 2 < s.size(); i ++)
            if(s[i] == s[i + 2]) return {i + 1, i + 3};

        return {-1, -1};
    }
};

int main() {

    string s;
    cin >> s;

    pair<int, int> res = Solution().unbalanced(s);
    printf("%d %d\n", res.first, res.second);

    return 0;
}
