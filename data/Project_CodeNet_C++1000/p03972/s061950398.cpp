#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl


signed main(void){
    int W,H;
    int p[114514],q[114514];
    vector<pair<int,int>> P;
    cin >> W >> H;
    REP(i,W){
        cin >> p[i];
        P.push_back({p[i],0});
    }
    REP(i,H){
        cin >> q[i];
        P.push_back({q[i],1});
    }
    int Ans=0;
    sort(P.begin(),P.end());
    
    int inter[214514]={};
    REP(i,P.size()){
        if(i==0){inter[0]=1;continue;}
        if(P[i].second==P[i-1].second){
            inter[i]=inter[i-1]+1;
        }else{
            inter[i]=1;
        }
    }
    //REP(i,P.size()){cout << inter[i] << " ";}cout << endl;
    
    int w=W+1,h=H+1;
    REP(i,P.size()){
        if(i==0){
            if(P[i].second==0){
                Ans+=P[i].first * h;
                //cout << "x " <<P[i].first MM h << endl;
            }else{
                Ans+=P[i].first * w;
                //cout << "y " <<P[i].first MM w << endl;
            }
            continue;
        }
        
        if(P[i].second==0){
            if(inter[i]==1){
                h-=inter[i-1];
            }
            Ans+=P[i].first * h;
            //cout << "x " <<P[i].first MM h << endl;
        }else{
            if(inter[i]==1){
                w-=inter[i-1];
            }
            Ans+=P[i].first * w;
            //cout << "y " <<P[i].first MM w << endl;
        }
        
    }
    
    cout << Ans << endl;
    
    return 0;
}

