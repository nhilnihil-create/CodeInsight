#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> m;
    int l = 0;
    rep(i,n) {
        cin >> a[i];
        m[a[i]]++;
        l = max(a[i],l);
    }
    bool can = true;
    if(l % 2){
        for(int i = 1; i < (l+1)/2; i++){
            if(m[i] > 0) can = false;
        }
        if(m[(l+1)/2] > 2) can = false;
        for(int i = (l+1)/2; i <= l; i++){
            if(m[i] < 2) can = false;
        }
    } else {
        for(int i = 1; i < l/2; i++){
            if(m[i] > 0) can = false;
        }
        if(m[l/2] != 1) can = false;
        for(int i = l/2 + 1; i <= l; i++){
            if(m[i] < 2) can = false;
        }
    }
    cout << (can? "Possible" : "Impossible") << endl;
    return 0;
}