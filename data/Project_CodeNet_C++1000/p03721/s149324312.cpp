#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;cin>>n>>k;
    vector<pair<long long, long long > >nos(n);
    long long a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        nos[i]=make_pair(a,b);
    }
    sort(nos.begin(),nos.end());
    int i=0;
    while(k!=0){
        if(k<=nos[i].second){cout<<nos[i].first;break;}
        k-=nos[i].second;
        i++;
    }
}