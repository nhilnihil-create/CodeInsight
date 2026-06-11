#include <iostream>
//#include <vector>
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

    LL num=0;
    for(LL i=0; i<s.size()-1; i++){
        if(s[i]!=s[i+1]){
            num++;
        }
    }

    cout << num << endl;

    return 0;
}
