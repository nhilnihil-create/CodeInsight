#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
    
    string S;
    cin >> S;
    
    map<char, bool> m;
    for(char c = 'a'; c != '{'; c++){
        m[c] = false;
    }
    
    for(int i = 0; i < S.size(); i++){
        m[S[i]] = true;
    }
    
    for(auto a : m){
        auto ans_C = a.first;
        auto ans_Cnt = a.second;
        if(ans_Cnt == 0){
            cout << ans_C << endl;
            return 0;
        }
    }

    cout << "None" << endl;
    
}
