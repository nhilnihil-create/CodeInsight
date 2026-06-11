#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    int N,M;cin>>N>>M;
    
    vector<int> cnt(M+2,0),yaku[M+1];
    
    for(int i=1;i<=M;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                yaku[i].push_back(j);
                if(j*j!=i) yaku[i].push_back(i/j);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        int a,b;
      scanf("%d",&a);
      scanf("%d",&b);
        if(a==b){
            for(int j=0;j<yaku[a].size();j++){
                int c=yaku[a][j];
                cnt[c]++;
                cnt[c+1]--;
            }
        }else if(a-1<=b-a+1){
            cnt[1]++;
            cnt[b+1]--;
        }else if(b-a+1<=20){
            set<int> S;
            
            for(int i=a;i<=b;i++){
                for(int j=0;j<yaku[i].size();j++){
                    int c=yaku[i][j];
                    S.insert(c);
                }
            }
            for(set<int>::iterator it=S.begin();it!=S.end();it++){
                cnt[*it]++;
                cnt[*it+1]--;
            }
            
        }else{
            
            cnt[1]++;
            cnt[b-a+2]--;
            cnt[a]++;
            cnt[b+1]--;
            
            int now=2;
            while(1){
                int l=(a+now-1)/now,r=b/now;
                if(l<=b-a+1){
                    if(r>b-a+1){
                        cnt[b-a+2]++;
                        cnt[r+1]--;
                    }
                    break;
                }else{
                    cnt[l]++;
                    cnt[r+1]--;
                }
                now++;
            }
        }
    }
    
    for(int i=2;i<=M;i++){
        cnt[i]+=cnt[i-1];
    }
    
    for(int i=1;i<=M;i++){
        cout<<cnt[i]<<"\n";
    }
}


