#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
using ll=long long;

int n;
map<int,int> A;

int main(){
    cin>>n;
    int m1=0,m2=0;
    rep(i,0,n){
        int a;cin>>a;
        A[a]++;
        if(A[a]%2==0){
            if(a>m1){
                m2=m1;m1=a;
            }else if(a<=m1&&a>m2){
                m2=a;
            }
        }
    }
    cout<<(ll)m1*(ll)m2<<endl;
}