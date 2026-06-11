#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> sorted;
int arr[100005];
map<int,int> m;
int main(){
scanf("%d",&n);
for (int x = 0; x<n; x++){
    int t;
    scanf("%d",&t);
    arr[x] = t;
    sorted.push_back(t);
}
sort(sorted.begin(),sorted.end());
for (int x = 0; x<n; x++){
    m[sorted[x]] = x;
}
int ans = 0;
for (int x = 0; x<n; x++){
    if (x%2!=m[arr[x]]%2){
        ans++;
    }
}
printf("%d",ans/2);
}
