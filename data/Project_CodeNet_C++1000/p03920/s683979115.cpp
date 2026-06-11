#include <bits/stdc++.h>
using namespace std;
int main(){
    int i, n, sum=0, cnt=0;
    vector <int> a;
    cin >>n;
    for(i=1;i<=n;i++){
        sum=sum+i;
        a.push_back(i);
        cnt++;
        if(sum>=n) break;
    }
    for(auto ans : a){
        if(sum-n!=ans) cout << ans <<endl;
    }
    return 0;
}