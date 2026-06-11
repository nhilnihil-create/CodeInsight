#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 1000000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
 
LL a[N];
LL before[N],last[N];
int main() {
    int n;
    scanf("%d",&n);
 
    LL maxSum=0,minSum=0;
    priority_queue<LL> minSumQ;
    priority_queue<LL, vector<LL>, greater<LL> > maxSumQ;
    for(int i=1;i<=3*n;i++){
        scanf("%d",&a[i]);
        if(i<=n){
            maxSum+=a[i];
            maxSumQ.push(a[i]);
        }
        else if(i>2*n){
            minSum+=a[i];
            minSumQ.push(a[i]);
        }
    }
 
    before[n]=maxSum;
    for(int i=n+1;i<=2*n;i++) {
        LL temp=maxSumQ.top();
        if(temp<a[i]){
            maxSum+=a[i]-temp;
            maxSumQ.pop();
            maxSumQ.push(a[i]);
        }
        before[i]=maxSum;
    }
 
    last[2*n]=minSum;
    for(int i=2*n-1;i>=n;i--){
        LL temp=minSumQ.top();
        if(temp>a[i+1]){
            minSum+=a[i+1]-temp;
            minSumQ.pop();
            minSumQ.push(a[i+1]);
        }
        last[i]=minSum;
    }
 
    LL res=before[n]-last[n];
    for(int i=n+1;i<=2*n;i++)
        res=max(res,before[i]-last[i]);
    printf("%lld\n",res);
 
    return 0;
}