#include <bits/stdc++.h>
using namespace std;
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    //これは最小二乗法だな...
    int N; cin>>N;
    vector<int> A(N);
    rep(i,N){
        cin>>A.at(i);
    }
    int A_total = accumulate(A.begin(),A.end(),0);
    double A_mean = (double)A_total/(double)N;
    double A_mean_int = round(A_mean);

    int sum_of_squares=0;    
    rep(i,N){
        sum_of_squares += pow((A.at(i)-A_mean_int),2);
    }
    cout<<sum_of_squares<<endl;



}