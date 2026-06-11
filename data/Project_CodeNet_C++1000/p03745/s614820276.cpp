#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    vector<int> a(100000, 0);
    int inc = 1;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int initial=0;
    for(int i=1; i<n; i++){
        initial++;
        if(a[i] != a[0]){
            if(a[i] > a[0]) inc = 1;
            if(a[i] < a[0]) inc = -1; 
            break;
        }
    }
    
    int cnt = 0;
    for(int i=initial+1; i<n; i++){
        if(inc==0){
            if(a[i]==a[i-1]) continue;
            if(a[i]>a[i-1]) inc=1;
            if(a[i]<a[i-1]) inc=-1;
        }else if(inc == 1){
            if(a[i]<a[i-1]){
                inc=0; cnt++;
            }
        }else if(inc == -1){
            if(a[i]>a[i-1]){
                inc=0; cnt++;
            }
        }
    }
    cout << cnt+1 << endl;
    return 0;
}