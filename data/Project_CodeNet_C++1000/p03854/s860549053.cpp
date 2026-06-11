#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
int main(){
    string S;
    cin >> S;
 
    vector<string> tokens = { "dreamer", "dream","erase", "eraser"};
 
    while (S.size() > 0) {
        bool hit = false;
        for(int i=0; i<tokens.size(); i++) {
            string t = tokens[i];
            if (S.size() >= t.size() && S.substr(S.size() - t.size(), t.size()) == t) {
                S = S.substr(0, S.size() - t.size());
                hit = true;
                break;
            }
        }
        if (!hit) {
            cout << "NO" << endl;;
            return 0;
        }
    }
 
    cout << "YES" << endl;;
    return 0;
}
