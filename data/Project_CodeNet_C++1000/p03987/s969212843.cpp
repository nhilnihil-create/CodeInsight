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
using namespace std;
#define INF 100000
#define MAX 100000
#define MOD 1000000007n
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
//typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

int main(){
    int N;
    cin>>N;
    vector<P> V(N);
    for(int i=0;i<N;i++){
        cin>>V[i].first;
        V[i].second=i+1;
    } 
    sort(V.begin(),V.end());
    set<int> S;
    S.insert(0); S.insert(N+1);
    ll ans=0;
    for(int i=0;i<N;i++){
        int x=V[i].second;
        auto it=S.lower_bound(x); it--;
        auto it2=it++;
        ans+=(ll)(*it-x)*(x-*it2)*(i+1);
        S.insert(x);
    }
    cout<<ans<<endl;
}

