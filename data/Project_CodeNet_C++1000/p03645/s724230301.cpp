#include <iostream>
#include <vector>

using namespace std;


typedef long long ll;


int main(){
    int N,M;
    cin>>N>>M;
    vector<int> iland[N];
    int a,b;
    for(int i=0;i<M;++i){
        cin>>a>>b;
        --a;--b;
        iland[a].push_back(b);
    }
    
    bool flag=false;
    
    for(int i=0;i<iland[0].size();++i){
        int il=iland[0][i];
        for(int j=0;j<iland[il].size();++j){
            if(iland[il][j]==N-1){
                flag=true;
                break;
            }
        }
        
    }
    
    if(flag){
        cout<<"POSSIBLE"<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
