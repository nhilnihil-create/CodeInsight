#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;cin >> S;
    reverse(S.begin(),S.end());
    int index = 0;
    int N = S.size();
    vector<string> memo = {"dream","dreamer","erase","eraser"};
    for(int i = 0; i < memo.size(); i++){
        reverse(memo[i].begin(),memo[i].end());
    }
    
    
    while(index < N){
        bool flag = true;
        for(int i = 0; i < memo.size(); i++){
            if(S.substr(index,memo[i].size()) == memo[i]){
                index += memo[i].size();
                flag = false;
            }
        }
        //cout << index << " " << N << endl;;
        if(flag){cout << "NO" << endl;return 0;}
    }
    cout << "YES" << endl;
    return 0;
}
