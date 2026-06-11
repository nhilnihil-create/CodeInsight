#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;cin>>a;v.push_back(a);
    }
    sort(v.rbegin(),v.rend());
    int pas1=-1,pas2=-1;
    for(int i=0;i<n-1;i++){
        int a=v[i],b=v[i+1];
        if(a==b){
            if(pas1==-1)pas1=a;
            else if(pas2==-1)pas2=a;
            i++;
        }
    }
    if(pas2==-1)cout<<"0\n";
    else cout<<(long long)pas1*pas2<<endl;
}