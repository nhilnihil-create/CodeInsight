#include<bits/stdc++.h>
using namespace std;
int main(){
     int t,n;
     cin>>n>>t;
     vector<string>v(n);
     for(int i=0;i<n;i++){
        cin>>v[i];
     }
     sort(v.begin(),v.end());
     for(int i=0;i<n;i++){
        cout<<v[i];
     }
     }
