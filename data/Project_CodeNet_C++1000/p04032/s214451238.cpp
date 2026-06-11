#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    string s; cin >> s;
    int n = s.size();
    for(char c = 'a'; c <= 'z'; ++c){
        int prev = -1;
        rep(i,n){
            if(s[i] == c){
                if(prev != -1 && i-prev <= 2){
                    cout << prev+1 << " " << i+1 << endl;
                    return 0;
                }
                prev = i;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
}