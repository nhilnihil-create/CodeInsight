#include <iostream>
#include <vector>
using namespace std;

int n,m,l=1;
vector<int> v[100000],p,q;
bool d[100000];

void f(int a, int b){
    d[a]=true;
    for(int i=0;i<v[a].size();i++){
        if(!d[v[a][i]]){
            l++;
            if(b==0){
                p.push_back(v[a][i]);
            }else{
                q.push_back(v[a][i]);
            }
            f(v[a][i], b);
            break;
        }
    }
}

int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    fill(d, d+n, false);
    p.push_back(0);
    f(0, 0);
    f(0, 1);
    cout<<l<<endl;
    for(int i=p.size()-1;i>=0;i--){
        cout<<p[i]+1;
        if(i>0)cout<<" ";
    }
    for(int i=0;i<q.size();i++){
        cout<<" "<<q[i]+1;
    }
    cout<<endl;
}
