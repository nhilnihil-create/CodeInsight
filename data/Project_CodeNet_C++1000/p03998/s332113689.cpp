#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution{

public:
    char winner(const vector<string>& s){

        char cur = 'a';
        vector<int> p(3, 0);
        while(p[cur - 'a'] < s[cur - 'a'].size())
            cur = s[cur - 'a'][p[cur - 'a'] ++];
        return cur - 'a' + 'A';
    }
};

int main() {

    vector<string> s(3);
    for(int i = 0; i < 3; i ++) cin >> s[i];
    printf("%c\n", Solution().winner(s));

    return 0;
}
