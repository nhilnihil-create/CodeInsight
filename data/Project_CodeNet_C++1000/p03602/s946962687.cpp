#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3005;
vector<pair<int,int>> v1[MAXN];
int dist[MAXN][MAXN];
int arr[MAXN][MAXN];
long long ans;
priority_queue<pair<pair<int,int>,int>> pq;
set<pair<int,int>> s1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool ok = false;
            for(int k=1;k<=n;k++){
                if(i==j||i==k||j==k){
                    continue;
                }
                if(arr[i][j] > arr[i][k]+arr[k][j]){
                    cout<<-1<<endl;
                    return 0;
                    
                }
                if(arr[i][j] ==arr[i][k]+arr[k][j]){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                ans+=arr[i][j];
            }
        }
    }
    cout<<ans/2<<endl;
    
}