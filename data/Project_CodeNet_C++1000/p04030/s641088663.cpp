#include <iostream>
//#include <vector>
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
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    string s;
    string ans="";
    cin >> s;
    for(LL i=0; i<s.size(); i++){
        if(s[i]=='0'){
            ans.push_back('0');
        }else if(s[i]=='1'){
            ans.push_back('1');
        }else{
            if(ans.size()!=0){
                ans.pop_back();
            }
        }
    }

    cout << ans << endl;

    return 0;
}
