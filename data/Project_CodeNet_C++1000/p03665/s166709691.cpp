#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,P;cin >> N >> P;
    vector<int> A(N);
    int m = 0;
    for(auto &i:A){
        cin >> i;
        if(i&1) m++;
    }
    if(P==0){
        if(m==0) cout << (1LL<<N) << endl;
        else cout << (1LL<<(N-1)) << endl;
    }else{
        if(m==0) cout << 0 << endl;
        else cout << (1LL<<(N-1)) << endl;
    }
}