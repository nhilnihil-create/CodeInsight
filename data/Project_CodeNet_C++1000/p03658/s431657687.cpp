#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <=(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
   int l[60];
   int sum=0;
int main(){
   int n,k;
   cin>>n>>k;
   rep(i,n)cin>>l[i];
   
   sort(l,l+n,greater<int>());
   
   for(int i=0;i<k;i++){
     sum+=l[i];
   }
   cout<<sum<<endl;
}