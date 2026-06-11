
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int x = 0;
    int n;
    string s;
    cin >> n >> s;
    int maxi = 0;
    rep(i,n){
        if(s.at(i) == 'I'){
            x++;
            maxi = max(maxi, x);
        }
        else{
            x--;
        }
    }
    cout << maxi << endl;
    
}