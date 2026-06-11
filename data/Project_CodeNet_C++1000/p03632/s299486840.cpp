#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main(void){

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = min(b, d) - max(a, c);
    if(ans < 0){
        cout << 0 << "\n";
    }else{
        cout << ans << "\n";
    }

    return 0;
}
