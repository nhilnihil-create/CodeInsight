#include <iostream>

using namespace std;


class Solution{

public:
    string process(const string& s){

        string res = "";
        for(char c: s)
            if(c == 'B'){
                if(res.size()) res.pop_back();
            }
            else res += c;
        return res;
    }
};

int main() {

    string s;
    cin >> s;
    cout << Solution().process(s) << endl;
    
    return 0;
}
