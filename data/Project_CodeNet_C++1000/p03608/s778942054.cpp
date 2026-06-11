#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> dista;

int recur(vector<int>& r, vector<bool>& flag, int d=0, int lastIndex=-1){
    int minDista = INT_MAX;
    bool endflag = true;
    for(int i=0;i<flag.size();++i){
        if(flag[i]){
            flag[i]=false;
            if(lastIndex==-1)
                minDista = min(minDista, recur(r, flag, d, r[i]));
            else
                minDista = min(minDista, recur(r, flag, d+dista[lastIndex][r[i]], r[i]));
            flag[i]=true;
            endflag = false;
        }
    }
    if(endflag)
        return d;
    return minDista;
}
int main(){
    int n, m, R;
    cin >> n >> m >> R;
    vector<int> r(R);
    for(int i=0;i<R;++i){
        cin >> r[i];
        --r[i];
    }
    dista = vector<vector<int>>(n, vector<int>(n, INT_MAX));
    for(int i=0;i<n;++i){
        dista[i][i]=0;
    }
    int a, b, c;
    for(int i=0;i<m;++i){
        cin >> a >> b >> c;
        --a, --b;
        dista[a][b]=c;
        dista[b][a]=c;
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dista[i][k]!=INT_MAX && dista[k][j]!=INT_MAX)
                    dista[i][j] = min(dista[i][j], dista[i][k]+dista[k][j]);
            }
        }
    }
    vector<bool> flag(R, true);
    cout << recur(r, flag);

    return 0;
}