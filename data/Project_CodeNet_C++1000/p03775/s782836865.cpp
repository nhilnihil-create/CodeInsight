#include <bits/stdc++.h>
using namespace std;
     
#define rep(i,n) for (int i = 0; i < (int)(n);i++)

int main() {
    long long N,buf;
    vector<int> ans;
    cin >> N;
    for(long long i=1;i*i<=N;i++){
        if(N%i==0){
            buf = N/i;
            if(to_string(buf).length()>to_string(i).length()){
                ans.push_back(to_string(buf).length());
            }else{
                ans.push_back(to_string(i).length());
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.at(0) << endl;
}