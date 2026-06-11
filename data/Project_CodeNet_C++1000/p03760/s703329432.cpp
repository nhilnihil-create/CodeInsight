#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    string o,e;
    cin >>o>>e;
    int d=o.size()-e.size();
    for(int i=0;i<e.size();i++){
        cout<<o[i]<<e[i];
    }
    int s=o.size();
    if(d)cout<<o[s-1];
    cout<<endl;
    return 0;
}