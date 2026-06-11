#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,ave;
    cin >> n >> ave;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x.at(i);
        x.at(i) -= ave;
    }
    vector<vector<ll>> dp(n,vector<ll>(5000,0));
    dp.at(0).at(x.at(0)+2500)++;
    dp.at(0).at(2500)++;
    for(int j=1; j<n; j++){
        for(int k=0; k<5000; k++){
            dp.at(j).at(k) += dp.at(j-1).at(k);
            if(k-x.at(j)>=0 && k-x.at(j)<5000){
                dp.at(j).at(k) += dp.at(j-1).at(k-x.at(j));
            }
        }
    }
    /*
    for(int i=0; i<10; i++){
        for(int j=2500; j<2501; j++){
            cout << dp.at(i).at(j) << " ";
        }
        cout << endl;
    }*/
   cout << dp.at(n-1).at(2500) -1 << endl;
}