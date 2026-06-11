#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> s(N);
    for (int i = 0; i < N; i++){
        cin >> s.at(i);
    }

    int ssum=accumulate(s.begin(),s.end(),0);
    
    vector<vector<int>> dp(N+1,vector<int>(ssum+1));
    for (int j = 0; j < ssum+1; j++){
        dp.at(0).at(j)=0;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < ssum+1; j++){
            if(j-s.at(i)>=0){
                dp.at(i+1).at(j)=max(dp.at(i).at(j-s.at(i))+s.at(i),dp.at(i).at(j));
            }
            else{
                dp.at(i+1).at(j)=dp.at(i).at(j);
            }
        }
    }

    int ans=dp.at(N).at(ssum);
    for (int i = 1; i < ssum; i++){
        if(ans%10!=0 || ans==0){
            break;
        }
        ans=dp.at(N).at(ssum-i);
    }

    cout << ans << endl;

          
}