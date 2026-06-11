#include <bits/stdc++.h>

using namespace std;


int main() {
    string x; cin>>x;
    int n = x.size();
    int s = 0 , t = 0;
    int cnt = 0;
    int mx = 0;
    bool toggle = 0;
    for(int i = 0 ; i < n; ++i){
        if(x[i] == 'S'){
            s++;
        }
        else if(x[i] == 'T' && s){
            s--;
            cnt++;
        }
    }
    cout<<n - cnt * 2<<"\n";
}