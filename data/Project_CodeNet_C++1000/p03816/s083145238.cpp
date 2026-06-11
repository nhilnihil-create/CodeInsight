#include<bits/stdc++.h>
using namespace std;
int n,ans,maxx;   
int a[100005],shu[100005];   
int main(){
    cin >> n;  
    for(int i = 1;i <= n;i++){
        cin >> a[i]; 
        shu[a[i]]++; 
        if(a[i] > maxx) maxx = a[i];  
    }
    for(int i = 1;i <= maxx;i++)
        if(shu[i] > 1)   
    ans += shu[i] - 1; 
    if(ans % 2 == 1) ans++;   
    cout << n - ans << endl;
    return 0;
}