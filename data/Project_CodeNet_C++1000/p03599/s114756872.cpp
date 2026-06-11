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
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int mx=f/(100*a);
    int my=f/(100*a);
    int ansu=0,anss=100*a;
    double ans=0.0;
    for(int x=0;x<=mx;x ++){
        for(int y=0;y<=my;y ++){
            if(x+y==0) continue;
            int xayb=x*a+y*b;
            int mz=(f-100*xayb)/c;
            if(100*xayb>=f) continue;
            for(int z=0;z<=mz;z++){
                if(c*z>xayb*e || 100*xayb+c*z>f) continue;
                int mw=(f-100*xayb-c*z)/d;
                for(int w=0;w<=mw;w++){
                    int czdw=c*z+d*w;
                    if(100*xayb+czdw>f) continue;
                    if(e*xayb<czdw) continue;
                    double ans2=(double)(czdw)/(100*xayb+czdw);
                    if(ans<ans2){
                        ansu=czdw;
                        anss=100*xayb+czdw;
                        ans=ans2;
                    }
                }
            }
        }
    }
    cout<<anss<<" "<<ansu<<endl;
}/*
./problem.exe
*/