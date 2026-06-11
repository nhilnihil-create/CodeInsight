#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    string S; cin>>S;
    int count=0;
    for(int i=1;i<S.size();i++){
        if(S[i]!=S[i-1])count++;
    }
    cout<<count;
    return 0;
}