#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int left = 0;
    int right = 0;
    int ans_left = 0;
    int ans_right = 0;
    rep(i,N){
        if (S[i] == '(') left++;
        if (S[i] == ')') right++;
        ans_left = max(ans_left, right - left);
    }
    left += ans_left;
    ans_right = left - right;
    rep(i,ans_left){
        S = "(" + S;
    }
    rep(i,ans_right){
        S = S + ")";
    }
    cout << S << endl;
}