#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N;
    cin >> N;
    vector<int> s(N);
    rep(i,N)cin>>s[i];

    long long sums = 0;
    rep(i,N)sums+=s[i];

    sort(s.begin(),s.end());

    if(sums%10 != 0){
        cout << sums << endl;
        return 0;
    }

    rep(i,N){
        if((sums-s[i])%10 != 0){
            cout << sums-s[i] << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
    
}