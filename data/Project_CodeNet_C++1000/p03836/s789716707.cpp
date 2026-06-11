#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;

int main(){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int difx=tx-sx;
    int dify=ty-sy;
    string ret;
    for(int i=0;i<dify;i++) ret+='U';
    for(int i=0;i<difx;i++) ret+='R';
    for(int i=0;i<dify;i++) ret+='D';
    for(int i=0;i<difx;i++) ret+='L';
    
    ret+='L';
    for(int i=0;i<dify+1;i++) ret+='U';
    for(int i=0;i<difx+1;i++) ret+='R';
    ret+='D';

    ret+='R';
    for(int i=0;i<dify+1;i++) ret+='D';
    for(int i=0;i<difx+1;i++) ret+='L';
    ret+='U';
    cout<<ret<<endl;
    return 0;
}
