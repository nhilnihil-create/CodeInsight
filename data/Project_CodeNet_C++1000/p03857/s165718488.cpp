#include<iostream>
#include<utility>
#include<map>
using namespace std;

long root(long x,long *uf){
    //cout << "x : " << x <<  "  uf : " << uf[x] << "\n";
    if(uf[x]==x){
        return x;
    }
    else{
        return uf[x] = root(uf[x],uf);
    }
}

void ufmerge(long x,long y,long *uf,long *rank_uf){
    x=root(x,uf);
    y=root(y,uf);
    if(x==y){
        return;
    }
    else{
        if(rank_uf[x]<rank_uf[y]){
            uf[x]=y;
        }
        else{
            uf[y]=x;
            if(rank_uf[x]==rank_uf[y]) rank_uf[x]++;
        }
    }
}

int main(){
    long N,K,L;
    long p,q,r,s;
    long road[200002];
    long rank_road[200002];
    long rail[200002];
    long rank_rail[200002];
    map<pair<long,long>,long> mp_count;
    
    cin >> N >> K >> L;
    for(long i=0;i<=N;i++){
        road[i]=i;
        rank_road[i]=1;
        rail[i]=i;
        rank_rail[i]=1;
    }

    for(long i=0;i<K;i++){
        cin >> p >> q;
        ufmerge(p,q,road,rank_road);
    }

    for(long i=0;i<L;i++){
        cin >> r >> s;
        ufmerge(r,s,rail,rank_rail);
    }

    for(long i=1;i<=N;i++){
        root(i,road);
        root(i,rail);
    }

    for(long i=1;i<=N;i++){
        pair<long,long> p_temp=make_pair(road[i],rail[i]);
        auto itr = mp_count.find(p_temp);
        if(itr != mp_count.end()){
            mp_count[p_temp]++;
        }
        else{
            mp_count[p_temp]=1;
        }
    }

    for(long i=1;i<=N;i++){
        if(i!=1) cout << " ";
        pair<long,long> p_temp=make_pair(road[i],rail[i]);
        cout << mp_count[p_temp];
    }
    cout << "\n";
    
    return 0;
}