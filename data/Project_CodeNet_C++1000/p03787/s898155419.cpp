#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, m, i, x, y, nr, nrc, nrb, minim, j, nra;
long long sol;
int viz[DIM], num[DIM], ok[DIM], c[DIM], s[DIM];
vector<int> v[DIM];
void dfs(int nod){
    viz[nod] = 1;
    c[nod] = nr;
    num[nr]++;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            s[vecin] = 1 - s[nod];
            dfs(vecin);
        }
        else{
            if(s[vecin] != 1 - s[nod]){
                ok[nr] = 0;
            }
        }
    }
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i = 1; i <= n; i++){
        if(viz[i] == 0){
            nr++;
            ok[nr] = 1;
            dfs(i);
        }
    }
    for(i = 1; i <= nr; i++){
        viz[i] = 0;
        if(num[i] == 1){
            nra++;
            nrb++;
            nrc++;
        }
        else{
            nrb++;
            nrc++;
            if(ok[i] == 1){
                nrb++;
            }
        }
    }
    for(i = 1; i <= n; i++){
        if(num[ c[i] ] == 1){
            sol += n;
            continue;
        }
        if(viz[ c[i] ] == 1){
            sol += nra;
        }
        else{
            viz[ c[i] ] = 1;
            if(ok[ c[i] ] == 0){
                sol += nrc;
            }
            else{
                sol += nrb;
            }
        }
    }
    cout<< sol <<"\n";
}
