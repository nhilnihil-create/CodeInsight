#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Solution{

private:
    unordered_map<long long, int> dp;

public:
    int maxscore(const string& s){

        int n = s.size();
        int g = n - n / 2;

        int res = 0;
        for(int i = 0; i < g; i ++)
            res -= s[i] == 'p';

        for(int i = g; i < n; i ++)
            res += s[i] == 'g';

        return res;
    }
};

int main() {

//    cout << Solution().maxscore("gpg") << endl;
//    // 0
//
//    cout << Solution().maxscore("ggppgggpgg") << endl;
//    // 2

    string s;
    cin >> s;
    printf("%d\n", Solution().maxscore(s));

    return 0;
}
