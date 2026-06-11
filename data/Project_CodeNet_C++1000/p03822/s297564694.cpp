#include <bits/stdc++.h>
using namespace std;
#define int long long

int tournament(vector<int>* x,int i){
    if(x[i].empty())return 0;
    

    vector<int> y(x[i].size());
    for(int j=0;j<x[i].size();j++){
        y[j]=tournament(x,x[i][j]);
       // cerr << x[i][j] << endl;
    }
    sort(y.begin(),y.end(),greater<int>());
    //for(int j=0;j<y.size();j++)cerr << y[j]<< ' ';
    for(int j=0;j<y.size();j++)y[j]+=j+1;
   sort(y.begin(),y.end(),greater<int>());
    return y[0];
}

signed main(){
    int n;
    cin >>n;
    vector<int> x[n];
    int k;
    for(int i=1;i<n;i++){
        cin >> k;
        x[k-1].push_back(i);
    }
   cout << tournament(x,0);
    return 0;
}