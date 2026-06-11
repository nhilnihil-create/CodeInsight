#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n;
    cin>>n;
    vector<int>v;
    while(n>0){
        int rem=n%10;
        v.push_back(rem);
        n=n/10;
    }
    int f=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==9){
            f=1;
            break;
        }
    }
    if(f==1)cout<<"Yes";
    else cout<<"No";
}