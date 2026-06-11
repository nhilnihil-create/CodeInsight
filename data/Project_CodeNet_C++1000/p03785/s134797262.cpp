#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
long long c,k,cnt = 0,count=0;
cin >> n >> c >> k;
long long t[n];
for (int i = 0;i < n;i++){
    cin >> t[i];
}
sort(t,t+n);
for (int i = 0;i < n;){
    ++cnt;
    int start = i;
    while (i < n && t[i] - t[start] <= k && i - start < c) ++i;   
}
cout << cnt << endl;
}