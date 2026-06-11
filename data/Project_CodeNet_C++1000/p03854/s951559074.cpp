#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string S;
    cin >> S;
    reverse(S.begin(),S.end());
    vector<string> t = {"dream","dreamer","erase","eraser"};
    for(int i=0;i<4;i++){
        reverse(t[i].begin(),t[i].end());
    }
    ll N = S.size();
    string substr = "";
    for(int i=0;i<N;i++){
        substr += S[i];
        if(t.size()>7){
            break;
        }
        for(int j=0;j<4;j++){
            if(substr ==t[j]){
                substr ="";
                break;
            }
        }
    }
    if(substr.size()==0){
        cout << "YES" << endl;
    }else{
        cout <<"NO" << endl;
    }
    return 0;
}