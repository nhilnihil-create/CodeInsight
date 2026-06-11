#include <iostream>
#include <map>
using namespace std;


int main(void){
    int n;
    cin >> n;
    map<int,int> m;
    
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        m[a]++;
    }
    
    int ans = 0;
    for(auto p : m) {
        if (p.second % 2 == 1) ans++;
    }
    
    cout << ans << endl;
}
