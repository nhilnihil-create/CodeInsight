#include <bits/stdc++.h>
/* 本当は個別にヘッダファイルを読みだすべき
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
*/

using namespace std;

#define rep(i,a,n) for(int i=a,i<n,i++)
#define vvi vector<vector<int>>
#define vi vector<int>
#define pi pair<int,int>

#define ti tuple<int,int,int>
#define gi get<i> //get<i>(data)

int ctoi(char c){
    if(c >= '0' && c <= '9'){
        return c-'0';
    }
    return 0;
}

long long answer = 0;

int dfs(string s, int i, long long presum, long long sum){
    if(i == s.size() -1){//最後の文字まで到達
        sum += presum + ctoi(s.at(i));
        answer += sum;//答えに足して終了させる
        return 0;
    }else{
        presum += ctoi(s.at(i));
        dfs(s,i+1,presum*10,sum);
        sum += presum;
        dfs(s,i+1,0,sum);
        return 0;
    }
}

int main(){
    string S;
    cin >> S;
    
    dfs(S,0,0,0);
    cout << answer << endl;

    return 0;
}