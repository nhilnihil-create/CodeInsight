#include<iostream>
using namespace std;

int main(){
    int N;
    string s;
    cin >> N >> s;
    int cnt=0, left=0, right=0;
    for (int i=0; i<N; i++){
        if (s[i] == '('){
            if (cnt < 0) {
                left += -cnt; 
                cnt = 1;}
            else{
                cnt++;
            }
        }
        else if (s[i] == ')'){
            cnt--;
        }
    }
    if (cnt > 0) right += cnt;
    else left += -cnt;

    string ans = s;
    for (int i=0; i<left; i++){
        ans = '(' + ans;
    }
    for (int i=0; i<right; i++){
        ans += ')';
    }
    cout << ans << endl;
    return 0;
}