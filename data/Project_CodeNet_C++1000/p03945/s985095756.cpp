#include <iostream>
#include <cstdio>

using namespace std;


class Solution{

public:
    int min_to_win(const string& s){

        int res = -1;
        for(int start = 0, i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                res ++;
                start = i;
                i = start;
            }
        return res;
    }
};

int main() {

    string s;
    cin >> s;
    printf("%d\n", Solution().min_to_win(s));

    return 0;
}
