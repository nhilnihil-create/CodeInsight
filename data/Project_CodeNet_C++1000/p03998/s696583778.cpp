#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
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
//#define MAX 100100
#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    vector<string> s(3);
    vector<LL> idx(3, 0);
    LL turn=0;

    cin >> s[0];
    cin >> s[1];
    cin >> s[2];

    while(true){
        if(idx[turn]==s[turn].size()){
            break;
        }
        if(s[turn][idx[turn]]=='a'){
            idx[turn]++;
            turn=0;
        }else if(s[turn][idx[turn]]=='b'){
            idx[turn]++;
            turn=1;            
        }else{
            idx[turn]++;
            turn=2;            
        }
    }

    if(turn==0){
        cout << 'A' << endl;
    }else if(turn==1){
        cout << 'B' << endl;
    }else{
        cout << 'C' << endl;
    }

    return 0;
}
