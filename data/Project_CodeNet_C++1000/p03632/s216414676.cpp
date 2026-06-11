#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int ans = 0;
    for(int i=0;i<=100;i++){
        if(i>a&&i<=b&&i>c&&i<=d) ans++;
    }

    cout << ans << endl;
}