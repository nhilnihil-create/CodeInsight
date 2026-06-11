#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int>a(n);
    int total_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total_sum += a[i];
    }
    int res = total_sum;
    bool done = false;
    if(total_sum%10 == 0){
        sort(a.begin() , a.end());
        for(int i = 0; i < n; i++){
            if(a[i]%10 != 0){
                res -= a[i];
                done = true;
                break;
            }
        }
    }else{
        cout << res << endl;
        return 0;
    }
    if(done)
        cout << res << endl;
    else 
        cout << 0 << endl;
    
}
