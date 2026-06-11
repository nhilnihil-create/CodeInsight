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
    int N,p[21000],t;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>t;
        t--;
        p[t]=i+1;
    } 
    /*for(int i=1;i<N;i++){
        p[i]+=p[0];
    }*/

    ll a[21000],b[21000];
    b[0]=1000000000; a[0]=p[0];

    for(int i=1;i<N;i++){
        ll x=1000000000+p[i];
        if(p[i]>p[i-1]){
            b[i]=b[i-1]-1;
            a[i]=a[i-1]+1+p[i]-p[i-1];
        }else{
            a[i]=a[i-1]+1;
            b[i]=b[i-1]-1-(p[i-1]-p[i]);
        }
    }
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<b[i];
    }
    cout<<endl;
}
