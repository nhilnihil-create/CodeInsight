#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

vector<int> tonari[100010];

int main(){
    int N; cin>>N;

    vector<int> distf(N,-1),dists(N,-1);

    int a,b;
    for (int i = 0; i < N - 1; ++i) {
        cin>>a>>b; a--; b--;
        tonari[a].push_back(b);
        tonari[b].push_back(a);
    }
  

    //fennec
    queue<int> q;
    distf[0]=0;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto tsugi:tonari[node]){
            if(distf[tsugi]>=0) continue;
            distf[tsugi]=distf[node]+1;
            q.push(tsugi);
        }
    }

    //sunuke
    dists[N-1]=0;
    q.push(N-1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto tsugi:tonari[node]){
            if(dists[tsugi]>=0) continue;
            dists[tsugi]=dists[node]+1;
            q.push(tsugi);
        }
    }

  
    int f=0,s=0;
    for (int i = 0; i < N; ++i) {
        //printf("%d : fennec %d, sunuke %d \n",i,distf[i],dists[i]);
        if(distf[i]<=dists[i]) {
            f++;
        }
        else s++;
    }
    //cout<<f<<" "<<s<<endl;
    cout<<((f>s)?"Fennec":"Snuke")<<endl;

    return 0;
}