#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> furthest_left, furthest_right;
int ans;

void left(int a, int b){
    auto next_a = lower_bound(furthest_left[a].begin(), furthest_left[a].end(), -b);
    if(next_a == furthest_left[a].begin()){
        ans += 1;
        return;
    }
    else{
        ans += 1<<(prev(next_a) - furthest_left[a].begin());
        left(-*prev(next_a),b);
    }
}

void right(int a, int b){
    auto next_a = lower_bound(furthest_right[a].begin(), furthest_right[a].end(), b);
    if(next_a == furthest_right[a].begin()){
        ans += 1;
        return ;
    }
    else{
        ans += 1<<(prev(next_a) - furthest_right[a].begin());
        right(*prev(next_a),b);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    
    int l, q;
    cin >> l >> q;
    vector<int> a(q), b(q);
    for(int i=0; i<q; i++){
        cin >> a[i] >> b[i];
        a[i] -= 1;
        b[i] -= 1;
    }

    furthest_left.resize(n);
    furthest_right.resize(n);

    for(int i=0; i<n; i++){
        furthest_left[i].push_back(-(lower_bound(x.begin(), x.end(), x[i] - l) - x.begin()));
        furthest_right[i].push_back(upper_bound(x.begin(), x.end(), x[i] + l) - x.begin() - 1);
        //cout << furthest_left[i] << " " << furthest_right[i] << endl;
    }

    int j = 0;
    while(furthest_left[n-1][j] < 0){
        for(int i=0; i<n; i++){
            furthest_left[i].push_back(furthest_left[-furthest_left[i][j]][j]);
        }
        j += 1;

        bool flag = true;
        for(int i=0; i<n; i++){
            if(furthest_left[i][j] != furthest_left[i][j-1]) flag = false;
        }
        if(flag == true) break;
    }
    
    /*
    for(int x=0; x<=j; x++){
        for(int i=0; i<n; i++) cout << furthest_left[i][x] << " ";
        cout << endl;
    }
    cout << endl;
    */
    
    int k = 0;
    while(furthest_right[0][k] < n-1){
        for(int i=0; i<n; i++){
            furthest_right[i].push_back(furthest_right[furthest_right[i][k]][k]);
        }
        k += 1;

        bool flag = true;
        for(int i=0; i<n; i++){
            if(furthest_right[i][k] != furthest_right[i][k-1]) flag = false;
        }
        if(flag == true) break;
    }
    /*
    for(int x=0; x<=k; x++){
        for(int i=0; i<n; i++) cout << furthest_right[i][x] << " ";
        cout << endl;
    }
    */
    
    for(int i=0; i<q; i++){
        ans = 0;
        if(a[i] > b[i])  left(a[i], b[i]);
        if(a[i] < b[i]) right(a[i], b[i]);
        cout << ans << endl;
    }
    return 0;
}
