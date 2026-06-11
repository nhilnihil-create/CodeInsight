#include <bits/stdc++.h>
using namespace std;

int main(){
    string w;
    bool ans=true;
    int n=1;
    cin >> w;
    sort(w.begin(), w.end());
    for (int i = 1; i < w.size(); i++) {
        if (w[i-1] != w[i] & n%2!=0) {
                ans=false;
                n = 0;
        }
        n += 1;
    }
    if (n%2!=0) ans=false;
    if (ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
