#include <bits/stdc++.h>
using namespace std;

int arr[100002];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    vector<bool>visited(n+1, false);
    int idx = 1;
    int res = 0;
    bool visit = false;
    while(idx != 2){
        res += 1;
        if(!visited[idx]){
            visited[idx] = true;
            idx = arr[idx];
        }else{
            visit = true;
            break;
        }
    }
    
    if(!visit){
        cout << res << endl;
    }else{
        cout << -1 << endl;
    }
    
    
}
