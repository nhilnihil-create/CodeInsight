#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    vector<int> c(9,0);
    int n;  cin >> n;
    for(int i=0; i<n; i++){
        int a;  cin >> a;
        if(a < 3200) c[a/400]++;
        else c[8]++;
    }
    int mi, ma;
    mi = 0;
    ma = 0;
    for(int i=0; i<8; i++) if(c[i] > 0){mi++; ma++;}
    if(mi == 0) mi++;
    ma += c[8];
    cout << mi << " " << ma << endl;
    return 0;
}