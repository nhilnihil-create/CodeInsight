#include<bits/stdc++.h>
using namespace std;

vector<int> a(1000000);

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]==j+1 && a[j]==i+1){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}