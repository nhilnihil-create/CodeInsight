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
//#define MOD 998244353
//#define MAX 100100
#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    string s;
    cin >> s;
    vector<vector<LL>> al_list(s.size()+1, vector<LL>(26, 0));
    for(LL i=1; i<=s.size(); i++){
        for(LL j=0; j<26; j++){
            al_list[i][j]=al_list[i-1][j];
        }
        LL tmp=s[i-1]-'a';
        al_list[i][tmp]++;
    }

    bool is_ok;
    LL s_idx=NIL;
    LL e_idx=NIL;

    for(LL i=0; i<s.size(); i++){
        for(LL j=2; j<=3; j++){
            is_ok=false;
            if(i+j>s.size()){
                continue;
            }
            for(LL k=0; k<26; k++){
                if(al_list[i+j][k]-al_list[i][k]>=2){
                    is_ok=true;
                }
            }
            if(is_ok==true){
                s_idx=i+1;
                e_idx=i+j;
                //cout << s_idx << " " << e_idx << endl;
            }
        }
    }

    cout << s_idx << " " << e_idx << endl;

    //for(LL i=0; i<26; i++){
    //    cout << al_list[2][i] << endl;
    //}

    return 0;
}
