#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n),visited(n,false);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int index=0;
    bool no=false;
    int count=0;
    while(index!=1){
        if(visited[index]==true){
            no=true;
            break;
        }
        
        visited[index]=true;
        index=v[index]-1;
        count++;
    }
    if(!no){
        cout<<count;
    }
    else{
        cout<<"-1";
    }

}