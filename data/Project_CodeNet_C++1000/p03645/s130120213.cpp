#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<bool>v(n);
    vector<bool>vend(n);
    for(int i=0;i<m;i++)
    {
        int f,s;
        cin>>f>>s;
        f--,s--;
        if(f==0){
            v[s]=true;
        }
        else
        if(s==n-1){
            vend[f]=true;
        }
    }
    bool no=true;
    for(int i=0;i<n;i++){
        if(v[i]==true&&vend[i]==true){
            no=false;
            break;
        }
    }
    if(no){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<"POSSIBLE"<<endl;
    }

}
