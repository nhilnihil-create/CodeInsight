//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};



int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int h,w;
    int n;
    cin>>h>>w>>n;
    vector<int> a(n);
        rep(i,n) cin>>a.at(i);
    vector<vector<int>> b(h,vector<int>(w,-1));
    int x=0,y=0,cnt=0,now=0,now_cnt=0;
    while(cnt<h*w){
        b[y][x]=now+1;
        now_cnt ++;
        cnt ++;
        if(y%2==1){x --;}
        else{x ++;}

        if(x==w){
            x=w-1;
            y ++;
        }
        if(x==-1){
            x=0;
            y ++;
        }

        if(now_cnt==a[now]){
            now_cnt=0;
            now ++;
        }
    }
    rep(i,h){
        rep(j,w-1){
            cout<<b[i][j]<<" ";
        }
        cout<<b[i][w-1]<<endl;
    }
}
//./problem.exe