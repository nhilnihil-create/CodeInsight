#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    int n,c,k;cin>>n>>c>>k;
    vector<int> t(n);
    for(int i=0;i<n;i++) cin>>t[i];
    sort(t.begin(),t.end());
    int ans=0;
    int pa=0;
    int tm=0;
    for(int i=0;i<n;i++){
        if(pa==0) tm=t[i]+k;
        if(pa<c&&t[i]<=tm) pa++;
        if(pa==c||i==n-1||t[i+1]>tm){
            ans++;
            pa=0;
        }
    }
    cout<<ans<<endl;
}