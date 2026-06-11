#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int n,k;
    cin >> n >> k;
    vector<int> vec(n);
    rep(i,n) cin >> vec.at(i);
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    int max=0;
    for(int i=0;i<k;i++){
        max += vec.at(i);
    }
    cout << max << endl;
}