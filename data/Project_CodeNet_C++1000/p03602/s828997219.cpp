#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define mt make_tuple

int n;
ll d[303][303], sum=0;
bool ans;


int main(){
cin >> n;
rep(i, 1, n){
rep(j,1,n){
cin >> d[i][j];
sum+=d[i][j];
}
}

rep(k, 1, n){
rep(i, 1, n){
rep(j, 1, n){
if(d[i][j]>d[i][k]+d[k][j])ans=true;
}
}
}
if(ans)return 0*printf("%d", -1);


rep(i, 1, n){
rep(j, 1, n){
ans=false;
rep(k, 1, n){
if(d[i][k]+d[k][j]==d[i][j] && i!=k && j !=k)ans=true;
}
if(ans)sum-=d[i][j];
}
}



cout << sum/2 << endl;

return 0;}
