#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = log2((double)n);
    ans = pow(2,ans);
    cout<<ans; 
    return 0;
}