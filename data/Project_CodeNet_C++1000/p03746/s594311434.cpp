#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int main(){

    int N, M;
    cin >> N >> M;
    vector<int>path[101010];
    vector<int>flg(N+1, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    vector<int>A, B;
    
    for(int pos = 1;;){
        A.push_back(pos);
        int noPath = 1;
        flg[pos] = 1;
        for(int i = 0; i < path[pos].size(); i++){
            if(flg[path[pos][i]])continue;
            pos = path[pos][i];
            noPath = 0;
            break;
        }
        if(noPath)break;
    }
    for(int pos = 1;;){
        if(pos != 1)B.push_back(pos);
        int noPath = 1;
        flg[pos] = 1;
        for(int i = 0; i < path[pos].size(); i++){
            if(flg[path[pos][i]])continue;
            pos = path[pos][i];
            noPath = 0;
            break;
        }
        if(noPath)break;
    }
    reverse(A.begin(), A.end());
    cout << A.size() + B.size() << endl;
    for(int i = 0; i < A.size(); i++){
        if(i)cout << " ";
        cout << A[i];
    }
    for(int i = 0; i < B.size(); i++){
        cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}