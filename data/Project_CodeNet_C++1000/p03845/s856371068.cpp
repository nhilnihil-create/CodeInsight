#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> segundos;
    int n, m, aux, p, x;
    long long total=0;

    cin>>n;

    while(n--){
        cin>>aux;
        total+=aux;
        segundos.push_back(aux);
    }

    cin>>m;

    while(m--){
        cin>>p>>x;
        cout<<total-segundos[p-1]+x<<endl;
    }

    return 0;
}