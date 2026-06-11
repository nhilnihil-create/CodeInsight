#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-9;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    int h,w;cin>>h>>w;
    int ah,aw;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            string s;cin>>s;
            if(s=="snuke"){
                ah=i+1;
                aw=j+1;
            }
        }
    }
    char c='A'+(aw-1);
    cout<<c<<ah<<endl;

}
