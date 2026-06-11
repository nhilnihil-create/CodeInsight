#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

ll cnt[ll(1e6)] = {};

int main() {
    
    
    ll n,m;
    cin >> n >> m;
    for (ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    int flag = 0;
    for (ll i=0;i<=n;i++){
        if(cnt[i]%2 == 1){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    
}