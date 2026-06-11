#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n, m;
long long a[100000];
vector<int> a_inv[100001];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long cost = 0;
    for(int i = 0; i + 1 < n; i++){
        cost += min((a[i+1] + m - a[i]) % m, (a[i+1] + m - 1) % m + 1);
    }
    //cout << cost << endl;
    long long ans = cost;

    int between_i[100002] = {};
    for(int i = 1; i < n; i++){
        a_inv[a[i]].push_back(i);
        if(a[i-1] < a[i]){
            between_i[a[i-1]+1]++;
            between_i[a[i]]--;
        }else if(a[i-1] == a[i]){
        }else{
            between_i[1]++;
            between_i[a[i]]--;
            between_i[a[i-1] + 1]++;
        }
    }
    for(int i = 1; i <= m; i++){
        between_i[i] += between_i[i-1];
    }

    for(int i = 1; i <= m; i++){
        //cout << between_i[i] << endl;
    }
    for(int x = 2; x <= m; x++){
        cost -= between_i[x-1];
        for(int i = 0; i < a_inv[x-1].size(); i++){
            int pos = a_inv[x-1][i];
            cost -= (a[pos] + m - (x-1)) % m + 1;
            cost += (a[pos] + m - a[pos-1]) % m;
        }
        //cout << cost << endl;
        ans = min(ans, cost);
    }
    
    cout << ans << endl;
}
