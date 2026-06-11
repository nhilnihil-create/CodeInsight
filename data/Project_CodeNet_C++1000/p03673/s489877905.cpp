#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    deque<int> ans;
    ans.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(i%2 == 1) ans.push_front(a[i]);
        else ans.push_back(a[i]);
    }    
    if(n%2 == 1) reverse(ans.begin(),ans.end());
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}