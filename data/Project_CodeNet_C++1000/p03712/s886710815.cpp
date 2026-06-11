#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> >v(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<m+2;j++){
            if(i==0){
                cout<<"#";
                continue;
            }
            if(i==n+1){
                cout<<"#";
                continue;
            }
            if(j==0){
                cout<<"#";
                continue;
            }
            if(j==m+1){
                cout<<"#";
                continue;
            }
            cout<<v[i-1][j-1];
        }
        cout<<endl;
    }
}