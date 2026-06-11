#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

ll n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    n++;
    deque <int> ans;
    int b = 0;
    for(int i = 45 ; i >= 0 ; i--){
        if(b == 0 && (n >> i) & 1){
            b = 1;
            continue;
        }
        if(b == 0) continue;
        int x = ans.size();
        ans.push_back(x);
        if((n >> i) & 1){
            int x = ans.size();
            ans.push_front(x);
        }
    }
    int x = ans.size();
    for(int i = 0 ; i < x ; i++){
        ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto &i : ans) cout << i + 1 << " ";
    cout << endl;
}
