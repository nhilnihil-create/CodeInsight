#include <bits/stdc++.h>
using namespace std;
int dig[10];
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        dig[t]++;
    }
    while(1){
        int notYet = 0;
        string test = to_string(n);
        int len = test.size();
        for(int i = len - 1; i >= 0; i--){
            if(dig[test[i] - '0']){
                n++;
                test = to_string(n);
                i = len - 1;
                notYet = 1;
            }
        }
        if(!notYet){
            cout << n << '\n';
            break;
        }
    }
    return 0;
}
