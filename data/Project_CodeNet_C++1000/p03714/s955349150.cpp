#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll INF = 1LL << 60;

int main(){
 int n;
 cin >> n;
 priority_queue<int,vector<int>,greater<int>> rq;
 priority_queue<int> bq;
 vector<int> v(3*n);
 ll rans[100009];
 ll bans[100009];
 rep(i,n*3){
   cin >> v[i];
 }
 rep(i,n){
   rq.push(v[i]);
 }
 for (int w=2*n;w < 3*n;w++){
   bq.push(v[w]);
 }
 ll rsum=0,bsum=0;
 ll ans=-INF;
 rep(i,n){
   rsum+=v[i];
 }
 for (int r = 3*n-1; r  > 2*n-1; r--){
   bsum+=v[r];
 }
rans[0]=rsum;
bans[n]=bsum; 
  //printf("now : %d rsum : %lld bsum : %lld\n",now,rsum,bsum);
 int id=1;
 for (int j=n;j < n+n;j++){
     rq.push(v[j]);
     int tmp = rq.top();rq.pop();
     rsum+=v[j]-tmp;
     rans[id]=rsum;
     id++;
 }
 id=n-1;
 for (int j=2*n-1;j >= n-1;j--){
   bq.push(v[j]);
   int tmp = bq.top();bq.pop();
   //printf("now bsum : %lld\n",bsum);
   bsum+=v[j]-tmp;
   //printf("v[j] : %d\n",v[j]);
   //printf("bsum : %lld tmp : %d\n",bsum,tmp);
   bans[id]=bsum;
   id--;
 }
 for (int i = 0;i <= n;i++){
   ans=max(ans,rans[i]-bans[i]);
 }
 cout << ans << endl;
 return 0; 
}