#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    string S;cin>>S;
    int N=S.size();
    vector<vector<int>> next(N+1,vector<int>(26,-1));//i番目の次のアルファベットの位置(1-indexed)
    vector<int> canto(N+1,-1);
    for(int i=1;i<=N;i++){
        for(int j=i-1;j>=0;j--){
            if(next[j][S[i-1]-'a']!=-1) break;
            next[j][S[i-1]-'a']=i;
        }
    }
    
    for(int i=N;i>=0;i--){
        bool end=false;
        for(int j=0;j<26;j++){
            if(next[i][j]==-1) end=true;
        }
        if(end) canto[i]=0;
        else{
            int maxi=INF;
            for(int j=0;j<26;j++){
                maxi=min(maxi,canto[next[i][j]]);
            }
            canto[i]=maxi+1;
        }
    }
    
    int length=canto[0]+1,now=0;
    string T;
    
    for(int k=0;k<length;k++){
        int hozon=now;
        
        if(k==length-1){
            for(int j=0;j<26;j++){
                if(next[now][j]==-1){
                    T+=('a'+j);
                    cout<<T<<endl;
                    return 0;
                }
            }
        }
        
        for(int j=0;j<26;j++){
            now=next[now][j];
            if(canto[now]+k>=length-1){
                now=hozon;
                continue;
            }
            T+=('a'+j);
            break;
        }
    }
}

