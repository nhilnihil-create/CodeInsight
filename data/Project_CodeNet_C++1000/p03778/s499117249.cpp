#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main(void){

    int w, a, b;
    cin >> w >> a >> b;

    if(a > b){
        swap(a, b);
    }

    int ans = a+w-b;
    if(ans < 0){
        cout << -ans << "\n";
    }else{
        cout << 0 << "\n";
    }

    return 0;
}
