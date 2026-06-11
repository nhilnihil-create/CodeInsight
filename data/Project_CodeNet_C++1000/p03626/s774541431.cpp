#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vector<int>v;//0:横置き、1:縦置き
    for(int i=0;i<n;i++){
        if(s1[i]==s2[i])v.push_back(1);
        else{
            v.push_back(0);
            i++;
        }
    }
    long long x;
    if(v[0])x=3;
    else x=6;
    for(int i=1;i<v.size();i++){
        if(v[i-1])x*=2;
        if(v[i-1]==0 && v[i]==0)x*=3;
        x%=mod;
    }
    cout<<x<<endl;
    return 0;
}