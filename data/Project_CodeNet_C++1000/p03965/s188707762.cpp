#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll BIG=1e15;

int main(){
    string S; cin>>S;
    int G=0, P=0;
    for(int i=0;i<S.size();i++){
        if(S.at(i)=='g') G++;
        else P++;
    }

    cout<<(G-P)/2<<endl;

}