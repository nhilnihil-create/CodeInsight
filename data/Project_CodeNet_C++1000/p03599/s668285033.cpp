#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    
    double dens,mdens = 0;
    int msol=100*a,msug=0;
    for(int i=0; 100*a*i<=f; i++){
        for(int j=0; 100*a*i + 100*b*j<=f; j++){
            for(int k=0; 100*a*i + 100*b*j + c*k<=f && c*k<=(a*i+b*j)*e; k++){
                for(int l=0; 100*a*i + 100*b*j + c*k + d*l<=f && c*k+d*l<=(a*i+b*j)*e; l++){
                    dens = (double)(c*k+d*l)/(100*a*i + 100*b*j + c*k + d*l);
                    if(dens>mdens){
                        mdens = dens;
                        msol = 100*a*i + 100*b*j + c*k + d*l;
                        msug = c*k + d*l;
                    }
                }
            }
        }
    }
    
    cout << msol <<" "<< msug << endl;
    
    return 0;
}

