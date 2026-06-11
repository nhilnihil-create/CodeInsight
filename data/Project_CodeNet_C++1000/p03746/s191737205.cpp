#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, m, i, p, u, okp, oku, x, y, nod, vecin;
int viz[DIM], c[2 * DIM];
vector<int> v[DIM];
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    viz[1] = 1;
    p = u = n;
    c[p] = 1;
    while(okp == 0 || oku == 0){
        okp = oku = 1;
        nod = c[p];
        for(i = 0; i < v[nod].size(); i++){
            vecin = v[nod][i];
            if(viz[vecin] == 0){
                okp = 0;
                c[--p] = vecin;
                viz[vecin] = 1;
                break;
            }
        }
        nod = c[u];
        for(i = 0; i < v[nod].size(); i++){
            vecin = v[nod][i];
            if(viz[vecin] == 0){
                oku = 0;
                c[++u] = vecin;
                viz[vecin] = 1;
                break;
            }
        }
    }
    cout<< u - p + 1 <<"\n";
    for(i = p; i <= u; i++){
        cout<< c[i] <<" ";
    }
}
