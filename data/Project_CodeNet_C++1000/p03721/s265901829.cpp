#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i;
    long long k;
    cin >> n >> k;
    vector<vector<int>> ab(n,vector<int>(2));
    for(i=0;i<n;i++){
        cin >> ab.at(i).at(0) >> ab.at(i).at(1);
    }
    sort(ab.begin(),ab.end());i=0;
    while(true){
        k-=ab.at(i).at(1);
        if(k<=0){cout << ab.at(i).at(0) << endl;break;}
        i++;
    }
    return 0;
}