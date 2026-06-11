#include <iostream>
#include <set>
using namespace std;
int n,m,a[300][300],k[300],x=1e5;
set<int> s;

void f(int p){
    int c[300],d=0;
    fill(c, c+m, 0);
    for(int i=0;i<n;i++){
        bool f=true;
        while(f){
            if(s.find(a[i][k[i]])==s.end()){
                f=false;
            }else{
                k[i]++;
            }
        }
        c[a[i][k[i]]]++;
        if(c[a[i][k[i]]]>c[d])d=a[i][k[i]];
    }
    x=min(x, c[d]);
    s.insert(d);
    if(p<m-1)f(p+1);
}

int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            a[i][j]--;
        }
        k[i]=0;
    }
    f(0);
    cout<<x<<endl;
}
