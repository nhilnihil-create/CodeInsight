#include<bits/stdc++.h>
using namespace std;
int main(){
vector<string>x;
string y;
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>y;
    x.push_back(y);
}
sort(x.begin(),x.end());
for(int i=0;i<n;i++){
    cout<<x[i];
}
}
