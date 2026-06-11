#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string S;
    cin >> S;
    deque<int> dq;
    for(int i=0;i<S.size();i++){
        if(S[i] =='B'){
            if(dq.empty()){
                continue;
            }
            dq.pop_back();
        }else{
            dq.push_back(S[i]-'0');
        }
    }
    while(!dq.empty()){
        cout <<dq.front();
        dq.pop_front();
    }
    cout<<endl;

    return 0;
}