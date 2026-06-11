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

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    int n;
    int ans=0;
    bool is_ok=false;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        ans+=s[i];
    }

    sort(s.begin(), s.end());

    if(ans%10!=0){
        cout << ans << endl;
    }else{
        for(int i=0; i<n; i++){
            if(s[i]%10!=0){
                ans-=s[i];
                is_ok=true;
                break;
            }

        }
        if(is_ok==true){
            cout << ans << endl;
        }else{
            cout << 0 << endl;
        }
    }

    return 0;
}