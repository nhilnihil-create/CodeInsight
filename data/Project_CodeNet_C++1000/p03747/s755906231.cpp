#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long jouyo(long long a, long long mod){
    if(a>=0){
        return a%mod;
    }else{
        return (a+(abs(a)/mod+1)*mod)%mod;
    }
}

int main(){
    //input
    long long N, L, T;
    cin >> N >> L >> T;
    vector<long long> ants[2];
    long long X, W, W_first;
    long long i,j[2],t,t_past;
    cin >> X >> W_first;
    W_first--;
    ants[W_first].push_back(X);
    for(i=2; i<=N; i++){
        cin >> X >> W;
        W--;
        ants[W].push_back(X);
    }

    //calc
    long long W_another, W_now;
    long long shukai[2];
    long long ant_now;
    bool only_ant_existed[2];
    only_ant_existed[0]=0;
    only_ant_existed[1]=0;
    if(W_first==0){
        W_another=1;
    }else{
        W_another=0;
    }
    W_now=W_first;
    vector<long long> ants_ans;
    if(ants[W_another].size()<=0){
        if(W_first==0){
            for(i=0; i<ants[W_first].size();i++){
                ants_ans.push_back(jouyo(ants[W_first][i]+T,L));
            }
        }else{
            for(i=0; i<ants[W_first].size();i++){
                ants_ans.push_back(jouyo(ants[W_first][i]-T,L));
            }
        }
    }else{
        if(W_first==0){
            j[0]=0;
            j[1]=0;
            shukai[0]=0;
            shukai[1]=0;
        }else{
            j[0]=ants[0].size()-1;
            j[1]=0;
            shukai[0]=-1;
            shukai[1]=0;
        }
        t=0;
        while(1){
            if(W_now==0){
                t=((ants[1][j[1]]+L*shukai[1])-(ants[0][j[0]]+L*shukai[0]))/2+1;
                if(t>T){
                    break;
                }
                W_now=1;
                j[0]--;
                if(j[0]<0){
                    shukai[0]--;
                    j[0]=ants[0].size()-1;
                }
            }else{
                 t=((ants[1][j[1]]+L*shukai[1])-(ants[0][j[0]]+L*shukai[0]))/2+1;
                if(t>T){
                    break;
                }
                W_now=0;
                j[1]++;
                if(j[1]>=ants[1].size()){
                    shukai[1]++;
                    j[1]=0;
                }
            }
        }
        for(i=0; i<ants[0].size();i++){
            ants[0][i]=jouyo(ants[0][i]+T,L);
        }
        for(i=0; i<ants[1].size();i++){
            ants[1][i]=jouyo(ants[1][i]-T,L);
        }
        if(W_now==0){
            if(ants[1].size()>1){
                for(j[1]=ants[1].size()-1; j[1]>=1;j[1]--){
                    if(ants[1][j[1]]>=ants[0][j[0]]&&ants[1][j[1]-1]<ants[0][j[0]]){
                        break;
                    }
                }
            }
        }else{
            if(ants[0].size()>1){
                for(j[0]=ants[0].size()-1; j[0]>=1;j[0]--){
                    if(ants[0][j[0]]>ants[1][j[1]]&&ants[0][j[0]-1]<=ants[1][j[1]]){
                        break;
                    }
                }
            }
        }
        ant_now=ants[W_now][j[W_now]];
        while(ants_ans.size()<N){
            if((jouyo(ants[0][j[0]]-ant_now,L)<=jouyo(ants[1][j[1]]-ant_now,L)&&only_ant_existed[0]==0)||only_ant_existed[1]==1){
                ants_ans.push_back(ants[0][j[0]]);
                ant_now=ants[0][j[0]];
                j[0]++;
                if(j[0]>=ants[0].size()){
                    j[0]=0;
                }
                if(ants[0].size()<=1){
                    only_ant_existed[0]=1;
                }
            }else{
                ants_ans.push_back(ants[1][j[1]]);
                ant_now=ants[1][j[1]];
                j[1]++;
                if(j[1]>=ants[1].size()){
                    j[1]=0;
                }
                if(ants[1].size()<=1){
                    only_ant_existed[1]=1;
                }
            }
        }
    }

    //answer
    for(i=0; i<N; i++){
        cout << ants_ans[i] << endl; 
    }
    system("pause");
    return 0;
}