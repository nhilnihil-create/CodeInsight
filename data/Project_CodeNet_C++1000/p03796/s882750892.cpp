#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int INF = 1e9 + 7;
    long long ans = 1;
    for(int i = 2; i < n+1; i++) {
        ans = (ans*i)%INF;
    }
    cout << ans << endl;
    return 0;
}
