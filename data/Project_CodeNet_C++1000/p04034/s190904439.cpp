#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> nums(n,1),can(n,0);
    can[0] = 1;
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        a--, b--;
        
        if (can[a]) can[b] = 1;
        if (nums[a] == 1) can[a] = 0;
        nums[a]--;
        nums[b]++;
    }
    int res = 0;
    for (int i = 0; i < n; i++){
        if (can[i] && nums[i])res++;
    }
    
    cout << res << endl;
}