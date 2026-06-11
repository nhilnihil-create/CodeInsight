#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main(){
    int n,c,k;cin>>n>>c>>k;
    int t[n];
    int count=1;
    int riders=1;
    int q=0;
    rep(i,n)cin>>t[i];
    sort(t,t+n);
    for(int i=1;i<n;i++){
        if(t[i]-t[q]>k||riders==c){
            count++;
            riders=1;
            q=i;
        }
        else {
            riders++;
        }
    }
    cout<<count<<endl;
}