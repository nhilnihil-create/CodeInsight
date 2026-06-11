#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k,c,d,sum = 0,ans;
    cin >> n >> k;
    map<long long,int> a;

    for(int i = 0;i < n;i++){
        cin >> c >> d;
        a[c] += d;
    }
    for(auto m : a){
        ans = m.first;
        sum += m.second;
        if(sum >= k)break;
    }
    cout << ans << endl;
}
