#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;
    cin>>n;
    vector<int>v;
    while(n>0){
        int rem=n%10;
        n=n/10;
        v.push_back(rem);
    }
    if(v[0]==v[2])cout<<"Yes";
    else cout<<"No";
}
