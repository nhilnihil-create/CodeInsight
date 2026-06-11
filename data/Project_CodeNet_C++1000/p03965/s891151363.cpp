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
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    string s;
    cin >> s;
    LL s_size=s.size();
    LL ans=0;
    LL sum=0;
    vector<LL> s_sum(s_size);
    for(LL i=0; i<s_size; i++){
        if(s[i]=='g'){
            sum++;
        }else{
            sum--;
        }
        s_sum[i]=sum;
    }

    LL min_sum=s_sum[s_size-1];
    for(LL i=s_size-1; i>=0; i--){
        min_sum=min(min_sum, s_sum[i]);
        if(s[i]=='g' && min_sum>=2){
            min_sum=min_sum-2;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
