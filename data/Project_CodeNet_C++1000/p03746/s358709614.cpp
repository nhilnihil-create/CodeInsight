#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n,m,a,b;
vector<int>e[100009],A,B;
bool visited[100009];

int main(){
    cin>>n>>m;
    rep(i,m){
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    visited[a]=visited[b]=true;
    A.push_back(a);
    B.push_back(b);
    while(true){
        int i=0;
        while(i<e[A[A.size()-1]].size()&&visited[e[A[A.size()-1]][i]])i++;
        if(i==e[A[A.size()-1]].size())break;
        A.push_back(e[A[A.size()-1]][i]);
        visited[A[A.size()-1]]=1;
    }
    while(true){
        int i=0;
        while(i<e[B[B.size()-1]].size()&&visited[e[B[B.size()-1]][i]])i++;
        if(i==e[B[B.size()-1]].size())break;
        B.push_back(e[B[B.size()-1]][i]);
        visited[B[B.size()-1]]=1;
    }
    cout<<A.size()+B.size()<<endl;
    for(int i=A.size()-1;i>=0;i--)cout<<A[i]<<" ";
    rep(i,B.size()){
        if(i)cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
}