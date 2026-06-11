#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, k;
        cin >> n >> k;
        int cnt = 0;
        vector < int > a(k);
        for(int i = 0; i < k; i++){
                cin >> a[i];
                cnt += a[i] & 1;
        }
        if(cnt > 2){
                cout << "Impossible" << "\n";
                return 0;
        }
        for(int i = 0; i < k; i++){
                if(a[i] & 1){
                        if(cnt == 2){
                                swap(a[0], a[i]);
                                cnt = 0;
                        } else{
                                swap(a[k - 1], a[i]);
                        }
                }
        }
        vector < int > res;
        res.push_back(a[0] - 1);
        if(res[0] == 0){
                res.pop_back();
        }
        for(int i = 1; i < k - 1; i++){
                res.push_back(a[i]);
        }
        if(k > 1){
                res.push_back(a[k - 1] + 1);
        } else{
                res.push_back(1);
        }
        for(int i = 0; i < k; i++){
                cout << a[i] << " \n"[i + 1 == k];
        }
        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
}
