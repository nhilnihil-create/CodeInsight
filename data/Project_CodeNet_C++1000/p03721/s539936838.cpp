#include <iostream>
#include <vector>
//#include <string>
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
//#define MAX 100100
//#define NIL -1

int main(){
    LL n;
    LL k;
    LL ans;
    vector<pair<LL, LL>> ab;
    LL tmp_a;
    LL tmp_b;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> tmp_a >> tmp_b;
        ab.push_back(make_pair(tmp_a, tmp_b));
    }

    sort(ab.begin(), ab.end());
    for(int i=0; i<n; i++){
        if(k<=ab[i].second){
            ans=ab[i].first;
            break;
        }else{
            k=k-ab[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}
