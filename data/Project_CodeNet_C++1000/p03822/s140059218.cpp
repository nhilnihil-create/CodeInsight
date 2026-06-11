#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
vector<int> v[100000];
int z[100000],d[100000];
int f(int x){
    if(d[x]>-1)return d[x];
    int y=v[x].size();
    for(int i=0;i<y;i++){
        z[i]=f(v[x][i]);
    }
    sort(z, z+y, greater<int>());
    int r=0;
    for(int i=0;i<y;i++){
        r=max(r, z[i]+i+1);
    }
    return r;
}
int main(void){
    cin>>n;
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        a--;
        v[a].push_back(i);
    }
    fill(d, d+n, -1);
    for(int i=n-1;i>=0;i--){
        d[i]=f(i);
    }
    cout<<d[0]<<endl;
}
