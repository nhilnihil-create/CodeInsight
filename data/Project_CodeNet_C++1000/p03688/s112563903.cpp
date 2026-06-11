#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
using namespace std;
#define INF 110000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,int> P;


int main(){
    int N,a[110000];
    cin>>N;

    for(int i=0;i<N;i++) cin>>a[i];

    int maxa=0,mina=110000;
    for(int i=0;i<N;i++){
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
    }
    if(maxa-mina>=2) cout<<"No"<<endl;
    else if(maxa==mina){
        int x=a[0];
        if(x==N-1 || 2*x<=N) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else{
        int p=0,q=0;
        for(int i=0;i<N;i++){
            if(a[i]==mina) p++;
            else q++; 
        }
        if(maxa*2<=2*p+q && p<maxa) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


}
