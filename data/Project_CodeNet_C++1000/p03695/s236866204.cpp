#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(9);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k>=3200)a[8]++;
        else{a[k/400]++;}
    }
    int cnt=0;
    for(int i=0;i<8;i++){
        if(a[i]>0)cnt++;
    }
    if(cnt!=0)cout<<cnt<<" "<<cnt+a[8]<<endl;
    else cout<<1<<" "<<cnt+a[8]<<endl;
    return 0;
}