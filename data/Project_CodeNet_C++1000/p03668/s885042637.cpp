#include<iostream>
#include<algorithm>
#include<vector>
#define DIM 100005
using namespace std;
int n, i, sum, x, y;
int s[DIM];
vector<int> v[DIM];
void dfs(int nod, int t){
    int i, vecin;
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        if(vecin != t){
            dfs(vecin, nod);
            s[nod] ^= (s[vecin] + 1);
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(v[1].size() == 1){
        cout<<"Alice";
        return 0;
    }
    dfs(1, 0);
    if(s[1] == 0){
        cout<<"Bob";
    }
    else{
        cout<<"Alice";
    }
}
