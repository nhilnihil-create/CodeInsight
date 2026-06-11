#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    int sum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(),a.end());

    int j=0;
    while(sum%10==0 && j<n){
        if(a[j]%10!=0) sum -= a[j];
        j++;
    }

    if(sum%10==0) cout << 0 << endl;   
    else cout << sum << endl;

    return 0;
}