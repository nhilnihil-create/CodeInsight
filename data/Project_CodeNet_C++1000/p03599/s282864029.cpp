#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#include <math.h>
const int INF = 1001001001;
int main() {
    int N;
    double A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    vector<double>X;
    vector<double>Y;
    for(int i=0;i<=F;i++){
        for(int j=0;j<=F;j++){
            int x=i*A*100+j*B*100;
            if(x<=F){X.push_back(x);}
        }
    }
    for(int i=0;i<=F;i++){
        for(int j=0;j<=F;j++){
            int y=i*C+j*D;
            if(y<=F){Y.push_back(y);}
        }
    }
    double ans=0;int MAXX=0;int MAXY=0;
    for(int i=0;i<X.size();i++){
        for(int j=0;j<Y.size();j++){
          if((X[i]+Y[j])<=F&&Y[j]/(X[i]+Y[j])<=E/(100+E)){
              ans=max(ans,Y[j]/(X[i]+Y[j]));
              if(ans<=Y[j]/(X[i]+Y[j])){MAXX=X[i];MAXY=Y[j];}
          }
        }
    }
    cout<<MAXX+MAXY<<" "<<MAXY<<endl;
    return 0;
}