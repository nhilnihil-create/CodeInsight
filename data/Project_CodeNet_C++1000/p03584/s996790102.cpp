#include <bits/stdc++.h>
using LL = long long;
const LL MOD = 1e9+9;
using namespace std;

const int beam_with = 20;




int main(){
    int N;cin >> N;
    LL _K;cin >> _K;
    bitset<50> K(_K);
    vector<bitset<50>> bits;
    vector<LL> val;
    for(int a = 0;a < N;a++){
        LL A,B;cin >> A >> B;
        bits.push_back(A);
        val.push_back(B);
    }
    LL ans = 0;
    //cout<<K<<endl;
    for(int i = -1;i < 51;i++){
        if(K[i] == 0 && i != -1)continue;
        //cout<<i<<endl;
        LL ins_ans = 0;
        for(int j = 0;j < N;j++){
            bool result = true;
            for(int k = 49;k >= max(i,0);k--){
                if(i == k){
                    if(1 == bits.at(j)[k]){
                        result = false;
                        break;
                    }
                }else{
                    if(!(bits.at(j)[k] == 0 || K[k] == 1)){
                        result = false;
                        break;
                    }
                }
            }
            if(result){
                ins_ans += val.at(j);
              //  cout<<bits[j]<<endl;
            }
            //cout<<"ans:"<<ins_ans<<endl;
        }
        ans = max(ans,ins_ans);
    }
    cout<<ans<<endl;
}
