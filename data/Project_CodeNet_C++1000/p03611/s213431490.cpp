#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> cnt(pow(10,5));
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        cnt.at(a)++;
    }
    int ans=0;
    for(int i=1; i<cnt.size()-1; i++){
        ans = max(ans, cnt.at(i-1)+cnt.at(i)+cnt.at(i+1));
    }
    cout << ans << endl;
}