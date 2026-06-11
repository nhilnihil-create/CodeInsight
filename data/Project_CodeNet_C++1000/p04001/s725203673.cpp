#include<bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

string s;
ll ans = 0;

void sum_num(ll num, ll sum, int l){
    int N = s.size();
    if(l == N-1){
        //cout << sum + num << endl;  
        ans += sum + num;
        return;
    }

    sum_num(s[l+1]-'0', sum+num, l+1);

    sum_num(num*10 + (s[l+1]-'0'), sum, l+1);

}

int main(){

    cin >> s;

    sum_num(s[0]-'0',0,0);

    cout << ans << endl;  
}