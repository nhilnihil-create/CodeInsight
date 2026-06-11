#include<bits/stdc++.h>
using namespace std;

vector<int> a(100000);

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int z; cin >> z;
        a[i] = z-1;
    }
    
    bool flg = true;
    int pos = a[0];
    int res=1;
    while(true){
        
        if(pos == 1){
            break;
        }else if(res >= n){
            flg = false;
            break;
        }
        pos = a[pos]; res++;
    }
    if(flg) cout << res << endl;
    else    cout << "-1"<< endl;
    return 0;
}