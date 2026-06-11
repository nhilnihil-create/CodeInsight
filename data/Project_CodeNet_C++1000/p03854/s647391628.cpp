#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 10000100
//#define NIL -1

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<string> w={"dream", "dreamer", "erase", "eraser"};
    for(LL i=0; i<4; i++){
        reverse(w[i].begin(), w[i].end());
    }

    LL idx=0;
    bool is_word_ok;
    bool is_char_ok;
    while(idx<s.size()){
        is_word_ok=false;
        for(LL i=0; i<4; i++){
            is_char_ok=true;
            if(w[i].size()+idx<=s.size()){
                for(LL j=0; j<w[i].size(); j++){
                    if(s[idx+j]!=w[i][j]){
                        is_char_ok=false;
                        break;
                    }
                }
                if(is_char_ok==true){
                    is_word_ok=true;
                    idx+=w[i].size();
                    //cout << w[i] << endl;
                    break;
                }
            }
        }
        //cout << idx << " " << is_word_ok << endl;
        if(is_word_ok==false){
            break;
        }
    }

    if(is_word_ok==true){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
