#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    bool flag = true;
    for(int i = n-2;i>=1;i -= 2){
        s.pop_back();s.pop_back();
        if(s.substr(0,i/2) == s.substr(i/2,i/2)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}