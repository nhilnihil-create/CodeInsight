#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> s){return accumulate(s.begin(),s.end(),0);}
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n)cin >> s[i];
    sort(s.begin(),s.end());
    int sum = accumulate(s.begin(),s.end(),0);
    int cnt = 0,min = 0;
    rep(i,n){
        if(s[i] % 10 == 0)cnt++;
        else if(min == 0)min = s[i];
    }
    if(cnt == n)cout << 0;
    else if(sum % 10 == 0) cout << sum-min;
    else cout << sum;
}