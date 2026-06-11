#include<bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin>>N;
    
    int a;
    vector<int> cnt(1e5+3, 0);
    
    for(int i=0; i<N; i++){
        cin>>a;
        cnt[a]++;
        cnt[a+1]++;
        cnt[a+2]++;
    }

    int ans=0;
    for(int c : cnt){
        ans=max(c, ans);
    }

    cout<<ans<<endl;
    return 0;
}