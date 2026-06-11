#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string c;
    ll K;
    cin >> c >> K;
    for(int i=0;i<c.size()-1;i++){
        int t= c[i] -'a';
        int cost = (alpha.size()-t)%alpha.size();
        if(cost<=K){
            K-=cost;
            c[i] ='a';
        }
    }
    int t= c[c.size()-1]-'a';
    c[c.size()-1] = alpha[(t+K)%alpha.size()];
    cout << c << endl;

    return 0;
}