#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }

    sort(a.begin(),a.end());
    int ans=n;
    for(int i=0; i<n-1; i++){
        if(a.at(i)==a.at(i+1)){
            ans-=2;
            i+=1;
        }
    }
    cout << ans << endl;
}