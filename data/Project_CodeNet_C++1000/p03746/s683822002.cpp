#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

long long int n,m,now,r=100001,l=100000,a[100005],b[100005],res[200005]={};
long long int used[100005]={};
queue<long long int> qu[100005];

int main() {
    const long long int mod = 1000000007,INF=99999999999999;
	map<long long int, long long int>mp;
    string str[2005],tmp;
	cout << fixed << setprecision(10);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        qu[a[i]].push(b[i]);
        qu[b[i]].push(a[i]);
    }
    res[100000]=1;
    used[1]=1;
    now=1;
    while(!qu[now].empty()){
        if(used[qu[now].front()]==1){
            qu[now].pop();
        }else{
            now=qu[now].front();
            res[r]=now;
            r++;
            used[now]=1;
        }
    }
    
    now=1;
    while(!qu[now].empty()){
        if(used[qu[now].front()]==1){
            qu[now].pop();
        }else{
            
            now=qu[now].front();
            l--;
            res[l]=now;
            used[now]=1;
        }
    }
    cout<<r-l<<endl;
    for(long long int i=l;i<r;i++){
        cout<<res[i]<<" ";
    }
    
} 
