#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,c,k;
    cin>>n>>c>>k;
    vector<int> t(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    sort(t.begin(),t.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int j=i,cnt=0;
        while(j<n&&t[i]+k>=t[j]&&cnt<c) j++,cnt++;
        i=j-1;
        ans++;
    }
    cout<<ans<<endl;
}
