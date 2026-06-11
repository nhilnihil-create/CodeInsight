#include<iostream>
#include<vector>
#include<string>
#include<cstring>

// ref : https://qiita.com/nomikura/items/98e53c1eb0be7af15847

using ll = long long;

int n, a;
std::vector<int> card;

// dp[id][maisu]][sum] = id以上のindexからmaisu枚以上を選んで合計がsum以上で条件を満たす総数
ll dp[51][51][2501];

ll rec(int id, int maisu, ll sum){
    if(id >= n){
        if(maisu * a == sum && maisu > 0) return 1;
        else return 0;
    }

    if(dp[id][maisu][sum] != -1){
        return dp[id][maisu][sum];
    }

    ll ret = 0;
    // idのカードを選ぶか選ばないか
    ll yes = rec(id + 1, maisu + 1, sum + card[id]);
    ll no = rec(id + 1, maisu, sum);
    ret += yes + no;
    
    dp[id][maisu][sum] = ret;
    return ret;
}

int main(){
    std::cin >> n >> a;
    card.resize(n);
    for(int i = 0; i < n; i++){
        std::cin >> card[i];
    }

    std::memset(dp, -1, sizeof(dp));
    std::cout << rec(0, 0, 0) << std::endl;

    return 0;
}
