#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::string S){
    int pointer = 0;
    int need_left = 0;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] == '(') pointer++;
        else
        {
            if(pointer == 0) need_left++;
            else pointer--;
        }
    }
    int need_right = pointer;
    string res = "";
    for(int i = 0; i < need_left; ++i) res += '(';
    res += S;
    for(int i = 0; i < need_right; ++i) res += ')';
    cout << res << endl;
}


int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
