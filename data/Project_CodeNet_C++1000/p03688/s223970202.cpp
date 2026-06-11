#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
int a[1000123];
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int mx=-1;
    int mn=10000000000;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if(mx - mn >= 2){
        cout << "No";
        return 0;
    }
    if(mx == mn){
        bool good = 1, good2 = 1;
        for(int i = 1; i <= n; i++){
            if(2 * a[i] > n){
                good = 0;
            }
            if(n - 1 != a[i]){
                good2 = 0;
            }
        }
        if(!good&&!good2){
            cout << "No";
            return 0;
        }
        cout << "Yes";
        return 0;
    }
    int x = 0;
    int y = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == mn){
            x++;
        }
        else{
            y++;
        }
    }
    if(x + 1 <= mx && mx <= x + y / 2){
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
    }
