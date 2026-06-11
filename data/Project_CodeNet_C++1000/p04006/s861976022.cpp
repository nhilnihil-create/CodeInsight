#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int N;
ll a[2020], b[2020];
ll x;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>N>>x;

    ll s=0;
    for(int i=0;i<N;i++) cin>>a[i], b[i]=a[i], s+=a[i];

    ll res = 1e18;
    for(int k=0;k<N;k++) {
      res = min(res, s + k*x);
      s=0;
      for (int i=0;i<N;i++) {
        b[i] = min(b[i], a[(i+k+1)%N]);
        s += b[i];
      }
    }

    cout<<res<<endl;

    return 0;
}
