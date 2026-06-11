#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> num(100001);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        num[a]+=b;
    }
    for(int i=0;i<=100000;i++){
        k-=num[i];
        if(k<=0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}