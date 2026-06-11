#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int n,x;
    cin>>n>>x;
    if(x==1||x==2*n-1) cout<<"No";
    else{
        cout<<"Yes"<<endl;
        vector<int> A,B;
        rep(i,2*n-1) B.push_back(i+1);
        B.erase(B.begin()+x),B.erase(B.begin()+x-1),B.erase(B.begin());
        B.insert(B.begin()+n-2,x+1),B.insert(B.begin()+n-2,x),B.insert(B.begin()+n-2,1);
        rep(i,2*n-1) cout<<B[i]<<endl;
    }
}