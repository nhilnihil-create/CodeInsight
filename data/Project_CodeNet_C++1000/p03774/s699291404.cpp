#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M;
    cin >>N>>M;
    vector<pair<long long,long long>> P(N);
    vector<pair<long long,long long>> P1(M);

    for(int i=0;i<N;i++){
        int a,b;
        cin >>a>>b;
        P.at(i)=make_pair(a,b);
    }
    for(int i=0;i<M;i++){
        int a,b;
        cin >>a>>b;
        P1.at(i)=make_pair(a,b);
    }
    for(int i=0;i<N;i++){
         long long maxx=99999999999;
        int memo=0;
        for(int j=0;j<M;j++){
 
        long long x=abs(P.at(i).first-P1.at(j).first)+abs(P.at(i).second-P1.at(j).second);
        if(maxx>x){
         memo=j+1;
            maxx=x;
         }
        }
        cout<<memo<<endl;
    }
}