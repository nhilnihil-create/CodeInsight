#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> a){
    vector<int> score(9, 0);
    int kami_cnt = 0;
    for(auto i: a){
        if(i < 400) score[0] = 1;
        else if(i >= 400 && i < 800) score[1] = 1;
        else if(i >= 800 && i < 1200) score[2] = 1;
        else if(i >= 1200 && i < 1600) score[3] = 1;
        else if(i >= 1600 && i < 2000) score[4] = 1;
        else if(i >= 2000 && i < 2400) score[5] = 1;
        else if(i >= 2400 && i < 2800) score[6] = 1;
        else if(i >= 2800 && i < 3200) score[7] = 1;
        else{
            score[8] = 1;
            kami_cnt += 1;
        }
    }
    cout << max(score[8], accumulate(score.begin(), score.end()-1, 0)) << " " << accumulate(score.begin(), score.end()-1, 0)+kami_cnt << endl;
}


int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
