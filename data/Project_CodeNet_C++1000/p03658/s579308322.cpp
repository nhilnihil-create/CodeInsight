#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    int n, k, ans;
    cin >> n >> k;
    
    ans = 0;
    vector<int> a(n);
    
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    for(int i = 0; i < k; ++i){
        ans += a.at(i);
    }
    
    cout << ans << endl;
}
