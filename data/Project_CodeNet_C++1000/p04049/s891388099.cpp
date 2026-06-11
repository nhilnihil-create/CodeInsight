#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector<int> v[2000];

int f(int x, int y, int z, int w){
    int r=0;
    if(z>w)r++;
    for(int i=0;i<v[y].size();i++){
        if(v[y][i]!=x){
            r+=f(y, v[y][i], z+1, w);
        }
    }
    return r;
}

int main(void){
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int c=1e9;
    for(int i=0;i<n;i++){
        int d=0;
        if(k%2==0){
            d=f(-1, i, 0, k/2);
        }else{
            int e=0;
            for(int j=0;j<v[i].size();j++){
                int x=f(i, v[i][j], 1, k/2);
                int y=f(i, v[i][j], 1, k/2+1);
                d+=x;
                e=max(e, x-y);
            }
            d-=e;
        }

        c=min(c, d);
        //cout<<d<<endl;
    }
    cout<<c<<endl;
}
