#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int>v1,v2;
    for(int i=a+1;i<=b;i++)v1.push_back(i);
    for(int i=c+1;i<=d;i++)v2.push_back(i);
    int l1=v1.size();
    int count=0;
    int l2=v2.size();
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            if(v1[i]==v2[j])count++;
        }
    }
    cout<<count;
}
