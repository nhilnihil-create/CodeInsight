#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        G.at(a-1).push_back(b);
        G.at(b-1).push_back(a);
    }
    for(int i=0;i<N;i++){
        cout <<G.at(i).size() << endl;
    }
    return 0;

}