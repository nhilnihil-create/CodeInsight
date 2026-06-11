#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(100005);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a[k]++;
    }
    int cnt=0;
    for(int i=1;i<=100001;i++){
        cnt=max(cnt,a[i-1]+a[i]+a[i+1]);
    }
    cout<<cnt<<endl;
    return 0;
}