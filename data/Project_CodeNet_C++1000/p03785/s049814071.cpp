#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];

    int ans = 1;
    sort(t.begin(), t.end(), greater<int>());
    int tlim = t[0], pnum = 1;
    for(int i = 1; i < n; i++){
        if(t[i]+k < tlim || pnum == c){
            ans++;
            tlim = t[i];
            pnum = 1;
        }else{
            pnum++;
        }
    }
    cout << ans << endl;
    return 0;
}