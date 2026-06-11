#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution{

public:
    bool isBeautiful(const string& s){

        vector<int> freq(26, 0);
        for(char c: s) freq[c - 'a'] ++;

        for(int e: freq) if(e % 2) return false;
        return true;
    }
};

int main() {

    string s;
    cin >> s;
    printf("%s\n", Solution().isBeautiful(s) ? "Yes" : "No");

    return 0;
}
