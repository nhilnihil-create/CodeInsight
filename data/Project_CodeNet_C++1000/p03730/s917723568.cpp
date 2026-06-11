#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    vector<bool> isexist1(b, false);
    {
        int cur = a % b;
        while(!isexist1[cur]){
            isexist1[cur] = true;
            cur += a;
            cur %= b;
        }
    }

    vector<int> plusnum;
    for(int i = 1; i < b; i++){
        if(isexist1[i]) plusnum.push_back(i);
    }

    vector<bool> memo(b*100, false);
    memo[0] = true;
    for(int i = 1; i < b*100; i++){
        for(auto p : plusnum){
            if(i-p >= 0 && memo[i-p]){
                memo[i] = true;
                break;
            }
        }
    }

    string ans = "NO";
    for(int i = c; i < b*100; i += b){
        if(memo[i]){
            ans = "YES";
        }
    }
    cout << ans << endl;
    return 0;
}