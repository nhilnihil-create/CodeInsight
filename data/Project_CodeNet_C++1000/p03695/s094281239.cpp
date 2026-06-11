#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N)cin>>A[i];

    int special_count = 0;
    rep(i,N){
        int point = A[i];
        if(point <= 399)A[i] = 0;
        if(point >= 400 && point <= 799)A[i] = 1;
        if(point >= 800 && point <= 1199)A[i] = 2;
        if(point >= 1200 && point <= 1599)A[i] = 3;
        if(point >= 1600 && point <= 1999)A[i] = 4;
        if(point >= 2000 && point <= 2399)A[i] = 5;
        if(point >= 2400 && point <= 2799)A[i] = 6;
        if(point >= 2800 && point <= 3199)A[i] = 7;
        if(point >= 3200){
            A[i] = 8;
            special_count++;
        }
            
    }

    int count = 0;
    set<int> set1(A.begin(), A.end());
    for(int j: set1){
        if(j!=8){
            count+=1;
        }
    }

    int min_count = max({1, count});
    int max_count = special_count + count;

    cout << min_count << " " << max_count << endl;
    
    return 0;

}