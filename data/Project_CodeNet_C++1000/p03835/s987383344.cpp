#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){
    int k, s; cin>>k>>s;
    int cont = 0;
    for (int x=0; x<=k; x++)
        for (int y=0; y<=k; y++){
            int z = s - x - y;
            cont += (z>=0 && z<=k);
        }

    cout<<cont<<endl;
}

int main(){
    solve();
    Bye;
}