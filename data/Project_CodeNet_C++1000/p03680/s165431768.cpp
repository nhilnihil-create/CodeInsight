#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int get(int n){
    if(n%2==0)return n/2;
    else return 3*n+1;
}
bool vis[mxn];
int arr[mxn];
void dfs(int i=1, int dist=0){
    vis[i]=true;
    if(i==2){
        cout<<dist;
        exit(0);
    }
    if(!vis[arr[i]])dfs(arr[i],dist+1);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    dfs();
    cout<<-1;
}

