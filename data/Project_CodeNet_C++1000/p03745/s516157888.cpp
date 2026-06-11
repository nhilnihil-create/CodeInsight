#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
 
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    int ans = 1;
    bool up = false,down = false;
    rep(i, 0, n-1){
        if(up && a[i] > a[i+1]){
            up = false;
            ans++;
        } else if(down && a[i] < a[i+1]) {
            down = false;
            ans++;
        } else if(!up && a[i] < a[i+1]) {
            up = true;
        } else if(!down && a[i] > a[i+1]) {
            down = true;
        }
    }
    cout << ans << endl;
    
    return 0;
}
