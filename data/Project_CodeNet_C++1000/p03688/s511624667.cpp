#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 5100
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
const double PI = acos(-1);

int main(){
    int N,a[110000],A=0,B=110000;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
        A=max(A,a[i]);
        B=min(B,a[i]);
    }
    if(A-B>=2){
        cout<<"No"<<endl;
        return 0;
    }
    if(A==B){
        if(A==N-1 || A*2<=N) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
    int numA=0,numB=0;
    for(int i=0;i<N;i++){
        if(a[i]==A) numA++;
        else numB++;
    }
    if(numB+1<=A && A<=numB+numA/2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

