#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

const int N_MAX = 200005;
const int K_MAX = 1000000005;
int n, k;
vector<int> A;

vector<int> BIT;

void init(){
    BIT.assign(n + 2, 0);
}

void update(int s){
    for(int i = s; i <= n + 1; i += i & -i){
        BIT[i]++;
    }
}

int getSum(int s){
    int sum = 0;
    for(int i = s; i > 0; i -= i & -i){
        sum += BIT[i];
    }
    return sum;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int na;
        cin >> na;
        A.push_back(na);
    }
    init();

    vector<pair<long long int, int>> B;
    long long int total = 0;
    B.emplace_back(0, 0);
    for(int i = 0; i < n; i++){
        int na = A[i];
        total += na - k;
        B.emplace_back(total, i+1);
    }

    sort(B.begin(), B.end());

    int C[N_MAX+3];
    int num = 1;
    C[B[0].second] = num;
    for(int i = 1; i < B.size(); i++){
        if (B[i-1].first < B[i].first) num++;
        C[B[i].second] = num;
    }


    long long int ans = 0;

    for(int i = 0; i <= n; i++){
        ans += getSum(C[i]);
        update(C[i]);
    }
    cout << ans << endl;
    return 0;
}