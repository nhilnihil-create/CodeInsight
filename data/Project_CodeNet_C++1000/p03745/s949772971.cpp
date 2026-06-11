#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
long long a[n],cnt=0;
for (int i =0;i < n;i++){
     cin >> a[i];
    // cout << a[i] << endl;

}
for (int i = 0;i < n;i++){
        
        while(i+1 < n && a[i]==a[i+1]) ++i;

        if(i+1<n && a[i] < a[i + 1]){
            while(i+1 < n && a[i] <= a[i+1]) ++i;
        }

        else if(i+1 < n && a[i] > a[i+1]){
            while(i+1 < n && a[i] >= a[i+1]) ++i;
        }
        ++cnt; 
}
    cout << cnt << endl;
}
