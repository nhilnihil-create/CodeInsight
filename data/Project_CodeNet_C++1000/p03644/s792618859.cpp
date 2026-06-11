#include <bits/stdc++.h>
using namespace std;

int count(int n){
    int cnt = 0;
    while(n%2==0){
        n/=2;
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    int max = 0;
    int ans = 1;
    
    for(int i=1;i<=n;i++){
        if(max<count(i)){
            max = count(i);
            ans = i;            
        }
    }
    cout << ans << endl;
}