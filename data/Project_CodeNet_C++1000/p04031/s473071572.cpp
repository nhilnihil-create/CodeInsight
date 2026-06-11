#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    int ans=pow(10,9);
    for(int i=-100;i<=100; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            cnt+=(i-a.at(j))*(i-a.at(j));
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}