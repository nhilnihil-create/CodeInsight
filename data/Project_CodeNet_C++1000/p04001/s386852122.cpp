#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG


int64_t ans=0;
string s;

void brute(int64_t sum, int64_t num, int k=0){
    if(k == s.length()){
        ans += num+sum;
        return;
    }
    brute(sum*10+s[k]-'0', num, k+1);
    if(sum) brute(s[k]-'0', num+sum, k+1);
}
int main(){
    cin >> s;
    brute(0,0,0);
    cout << ans << endl;
}