#include <iostream>
#include <vector>
//#include <string>
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

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    int n;
    vector<int> a(8, 0);
    int a_free=0;
    int tmp_a;
    int ans_min=0;
    int ans_max;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        tmp_a/=400;
        if(tmp_a>=8){
            a_free++;
        }else{
            a[tmp_a]++;
        }
    }
    for(int i=0; i<8; i++){
        if(a[i]!=0){
            ans_min++;
        }
    }

    ans_max=ans_min+a_free;

    if(ans_min==0 && a_free!=0){
        ans_min=1;
    }

    cout << ans_min << " " << ans_max << endl;

    return 0;
}
