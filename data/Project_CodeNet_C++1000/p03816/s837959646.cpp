#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
#include <set>
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
    LL n;
    set<LL> a;
    LL tmp_a;
    cin >> n;
    for(LL i=0; i<n; i++){
        cin >> tmp_a;
        a.insert(tmp_a);
    }

    if(a.size()%2==0){
        cout << a.size()-1 << endl;
    }else{
        cout << a.size() << endl;
    }



    return 0;
}
