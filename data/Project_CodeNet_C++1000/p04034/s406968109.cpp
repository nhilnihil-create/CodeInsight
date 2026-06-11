#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main() {
    
    int N,M;
    cin >> N >> M;
    map<int,bool> red;
    map<int,int> cont;
    
    for(int i = 0; i < N;i++){
        red[i] = false;
        cont[i]++;
    }
    red[0]=true;
    int x,y;
    for(int i = 0; i < M;i++){
        cin >> x >> y;
        x--,y--;
        if(red[x]&&cont[x]-1!=0){
            cont[x]--;
            cont[y]++;
            red[y] = true;
        }else if(red[x]&&cont[x]-1==0){
            cont[x]--;
            cont[y]++;
            red[x] = false;
            red[y] = true;
        }else{
            cont[x]--;
            cont[y]++;            
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N;i++){
        if(red[i])ans++;
    }
    cout << ans <<endl;
}