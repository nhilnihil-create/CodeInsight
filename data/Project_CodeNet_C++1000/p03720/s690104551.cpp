#include <bits/stdc++.h>
using namespace std;
// ascii 97~122

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> vec(N,0);
    int a,b;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        vec.at(a-1)++;
        vec.at(b-1)++;
    }
    for(int x: vec){
        cout << x <<endl;
    }
}