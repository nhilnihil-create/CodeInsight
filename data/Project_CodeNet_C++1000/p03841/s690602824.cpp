#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
        x[i]--;
    }

    vector<pair<int,int>> xidx(n);
    for(int i=0;i<n;i++){
        xidx[i]=make_pair(x[i],i+1);
    }
    sort(xidx.begin(),xidx.end());

    vector<int> a(n*n,0);
    for(int i=0;i<n;i++){
        a[x[i]]=i+1;
    }

    int pos=0;
    for(int loop=0;loop<2;loop++){
        for(int idx=0;idx<n;idx++){
            int cnt=(loop==0 ? xidx[idx].second-1 : n-xidx[idx].second);
            for(int i=0;i<cnt;i++){
                if(a[pos]==0) a[pos]=xidx[idx].second;
                else i--;
                pos++;
            }
        }
    }
    
    vector<int> cnt(n*n,0);
    for(int i=0;i<n*n;i++){
        cnt[a[i]-1]++;
        if(cnt[a[i]-1]==a[i] && x[a[i]-1]!=i){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<n*n;i++){
        cout<<a[i]<<(i+1==n*n ? "\n" : " ");
    }
    
    return 0;
}