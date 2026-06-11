#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <cmath>
#define INF 100000000000
#define MOD 1000000007
#define ll long long int

#define int long long

using namespace std;

signed main(){
    int N; cin>>N;
    vector <int> a1;
    a1.resize(N);
    vector <int> a2=a1;
    vector <int> a3 = a1;
    for(int i=0;i<N;i++) cin>>a1[i];
    for(int i=0;i<N;i++) cin>>a2[i];
    for(int i=0;i<N;i++) cin>>a3[i];

    vector <int> fmax(N+1,0);
    vector <int> lmin(N+1,0);
    vector <int> ans(N+1,0);

    priority_queue <int, vector<int>, greater<int>> pf;
    int fsum = 0;

    for(int i=0;i<N;i++){
        pf.push(a1[i]);
        fsum += a1[i];
    }
    fmax[0] = fsum;

    for(int i=1;i<=N;i++){
        int origin = pf.top();
        if(a2[i-1] < origin) {fmax[i] = fsum;continue;}
        else {fsum = fsum - origin + a2[i-1];pf.pop();pf.push(a2[i-1]);fmax[i] = fsum;}
    }
    fsum = -INF;
    //##################


    priority_queue <int> pl;
    int lsum = 0;

    for(int i=0;i<N;i++){
        pl.push(a3[i]);
        lsum += a3[i];
        //cout<<lsum<<endl;
    }
    lmin[N] = lsum;

    for(int i=N-1;i>=0;i--){
        int origin = pl.top();
        //cout<<origin<<endl;
        if(a2[i] > origin) {lmin[i] = lsum;continue;}
        else {lsum = lsum - origin + a2[i];pl.pop();pl.push(a2[i]);lmin[i] = lsum;}
        //cout<<i<<" "<<lsum<<endl;
    }
    for(int i=0;i<=N;i++){
        ans[i] = fmax[i] - lmin[i];
    }

    int output = -INF * 100000;
    for(int i=0;i<=N;i++){
        output = max(output,ans[i]);
       // cout<<i<<" "<<fmax[i]<<" "<<lmin[i]<<endl;
    }
cout<<output<<endl;

    return 0;
}