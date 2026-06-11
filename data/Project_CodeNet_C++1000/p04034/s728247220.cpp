#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main () {
 int n,m; cin >> n >> m;
 vector<bool> flag(n,0); flag[0]=1;
 vector<int> mount(n,1);
 rep(i,m){
   int x,y; cin >> x >> y; x--;y--;
   if(mount[x]>=2 && flag[x]==1){
     flag[y]=1;
   }
   else if(mount[x]==1 && flag[x]==1){
     flag[x]=0;flag[y]=1;
   }
   mount[x]--;
   mount[y]++;
 }
 int cnt=0;
 rep(i,n){
   if(flag[i]==1)cnt++;
 }
 cout << cnt << endl;
}
