#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, i, a[100100], ans=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }
    for(i=0;i<n;i++){
        if(a[i]!=-1){
            if(a[a[i]]==i){
                ans++;
                a[a[i]]=-1;
            }
        }
    }
    cout << ans <<endl;
}

