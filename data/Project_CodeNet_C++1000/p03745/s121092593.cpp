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
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
  int t=-1;
    for(int i=0;i<n-2;){
      if((a[i]<a[i+1])||a[i]>a[i+1]) t=i;
        if(t!=-1&&((a[t]<a[t+1]&&a[i+1]>a[i+2])||(a[t]>a[t+1]&&a[i+1]<a[i+2]))){
            ans++;
            i+=2;
          t=-1;
        }else i++;
    }
    ans++;
    cout<<ans<<endl;
    return 0;
}