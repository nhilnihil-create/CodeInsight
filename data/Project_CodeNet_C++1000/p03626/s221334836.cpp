#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;
    queue<int> q;
    bool one = true;
    for (int i = 0; i < S1.size() - 1; i++){
        if (S1.at(i) == S1.at(i + 1)){
            if (i == 0) q.push(0);
            q.push(1);
            one = false;
            //cout << "case1" << endl;
        }
        else{
            if (i > 0 && i < S1.size() - 2){
                if (S1.at(i - 1) == S1.at(i)) {
                    //cout << "case2" << endl;
                    one = true;
                    continue;
                }
                else{
                    q.push(0);
                    //cout << "case3" << endl;
                }
                
            }
            else {
                q.push(0);
                //cout << "case4" << endl;
            }
        }
    }
    if (one) q.push(0);
    
    /*
    while (!q.empty()){
        int ans = q.front();
        q.pop();
        cout << ans << endl;
    }
    */
    int64_t ans = 3;
    int re = q.front();
    q.pop();
    while (!q.empty()){
        int p = q.front();
        q.pop();
        if (p == 0){
            if (re == 0){
                ans *= 2;
                ans %= 1000000007;
            }
            else {
                ans *= 1;
                ans %= 1000000007;
            }
        }
        else {
            if (re == 0){
                ans *= 2;
                ans %= 1000000007;
            }
            else {
                ans *= 3;
                ans %= 1000000007;
            }
        }
        re = p;
       // cout << ans << endl;
    }
    cout << ans << endl;
}