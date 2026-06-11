#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    for(int i = 0; i < k; i++){
        cin >> d[i];
    }

    int ans = 0;
    for(int i = n; i < 10 * n; i++){
        int x = i;
        bool f = false;
        vector<int> tmp;
        while(x > 0){
            tmp.push_back(x%10);
            x /= 10;
        }
        for(int y : tmp){
            for(int z : d){
                if(z == y){
                    f = true;
                    break;
                }
            }
            if(f) break;
        }

        if(!f){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}