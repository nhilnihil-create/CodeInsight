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
//#define MAX 200100
//#define NIL -1

int main() {
    int n;
    vector<LL> a;
    vector<LL> b;
    LL tmp_a;
    LL ans;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        a.push_back(tmp_a);
    }

    sort(a.begin(),a.end());
    LL num=1;
    int sq_idx=-1;
    int last_idx;
    for(int i=1; i<n; i++){
        if(a[i]!=a[i-1]){
            if(num>=2){
                b.push_back(a[i-1]);
                last_idx=i-1;
                if(num>=4){
                    sq_idx=i-1;
                }
            }
            num=1;
        }else{
            num++;
        }
        if(i==n-1){
            if(num>=2){
                b.push_back(a[i]);
                last_idx=i;
                if(num>=4){
                    sq_idx=i;
                }
            }
        }
    }

    //for(int i=0; i<n; i++){
    //    cout << a[i] << endl;
    //}

    sort(b.begin(),b.end(), greater<LL>());

    if(last_idx==sq_idx){
        ans=b[0]*b[0];
    }else if(b.size()>=2){
        ans=b[0]*b[1];
    }else{
        ans=0;
    }

    cout << ans << endl;

    return 0;
}
