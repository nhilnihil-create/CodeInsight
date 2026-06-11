#include<bits/stdc++.h>
using namespace std;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
void Main(){
    int N;cin>>N;
    vector<int> oya(N,-1);
    vector<vector<int>> ko(N);
    For(i,1,N){
        cin>>oya[i];oya[i]--;
        ko[oya[i]].push_back(i);
    }
    queue<int> que;
    vector<int> cnt(N,0),depth(N,0);
    For(i,0,N){
        if(ko[i].size()==0){
            que.push(i);
        }
    }
    while(true){
        int i=que.front();
        que.pop();
        vector<int> idepth;
        For(j,0,ko[i].size()){
            idepth.push_back(depth[ko[i][j]]);
        }
        sort(ALL(idepth));reverse(ALL(idepth));
        For(j,0,ko[i].size()){
            depth[i]=max(depth[i],idepth[j]+j+1);
        }
        /*cout<<"i= "<<i+1<<endl;
        For(t,0,N) cout<<depth[t]<<" ";
        cout<<endl;*/
        if(i==0) break;
        cnt[oya[i]]++;
        if(cnt[oya[i]]==ko[oya[i]].size()){
            que.push(oya[i]);
        }
    }
    cout<<depth[0]<<endl;
}
int main(){
    Main();
    return 0;
}