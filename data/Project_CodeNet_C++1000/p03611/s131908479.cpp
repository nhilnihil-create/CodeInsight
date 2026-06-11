#include <bits/stdc++.h>
using namespace std;

int main(){
        
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    
    map<int, int>mp;
    for(int i = 0; i < n; i++){
        mp[a[i]] += 1;
    }
    
    int res = 0;
    for(auto v : mp){
        //cout << v.first << " " << v.second << endl;
        int current = v.second;
        if(mp.find(v.first + 1) != mp.end()){
            current += mp[v.first + 1];
        }
        if(mp.find(v.first - 1) != mp.end()){
            current += mp[v.first - 1];
        }
        res = max(res, current);
    }
    
    cout << res << endl;
    
    
    return 0;
    
    
}
