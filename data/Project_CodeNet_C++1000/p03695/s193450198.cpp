#include <bits/stdc++.h>
using namespace std;

int give_numbers(int x){
        
    int res = 0;
    while(x >= 0){
        res += 1;
        x -= 400;
    }
    
    return res;
    
}



int main(){
    
    
    int n;
    cin >> n;
    
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    set<int>s;
    int out_3200 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 3200){
            s.insert(give_numbers(arr[i]));
        }else{
            out_3200 += 1;
        }
    }
    int mn = (int)s.size();
    int mx = mn + out_3200;
    if(mn == 0)mn = 1;
    
    cout << mn << " " << mx << endl;
    
    
}
