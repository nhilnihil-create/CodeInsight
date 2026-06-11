#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const int mod = 1e9 + 7;

using namespace std;

int n;
int res[N * N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        vector < pair < int, int > > v;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                res[x] = i;
                for(int j = 1; j < i; j++){
                        v.push_back({x, i});
                }
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector < int > A;
        for(int i = 1; i <= n * n; i++){
                if(res[i]){
                        for(int j = 1; j <= n - res[i]; j++){
                                A.push_back(res[i]);
                        }
                        continue;
                }
                if(!v.empty()){
                        if(v.back().fi < i){
                                cout << "No" << "\n";
                                return 0;
                        }
                        res[i] = v.back().se;
                        v.pop_back();
                } else{
                        if(A.empty()){
                                cout << "No" << "\n";
                                return 0;
                        }
                        res[i] = A.back();
                        A.pop_back();
                }
        }
        cout << "Yes" << "\n";
        for(int i = 1; i <= n * n; i++){
                cout << res[i] << ' ';
        }
}
