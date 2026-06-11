#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
    // input from txt （提出時にこの箇所は削除すること）
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    long long a[20] = {0};
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    const long long INF = 0xfffffffffffff;

    long long min_cost = INF;
    
    for (int i = 0; i < (1 << (N - 1)); i++) {
        bitset<15> bits(i);
        int visible = (int) bits.count() + 1;
        
        long long max_height = a[0];
        long long cost = 0;
        for (int j = 0; j < N - 1; j++) {
            if (!(i & (0x1 << j))) {
                if (a[j + 1] > max_height) {
                    max_height = a[j + 1];
                    visible++;
                    continue;
                }
                continue;
            }
            
            if (a[j + 1] > max_height) {
                max_height = a[j + 1];
                continue;
            }
            
            cost += max_height - a[j + 1] + 1;
            max_height++;
            
        }
        if (visible < K) {
            continue;
        }
        min_cost = min(min_cost, cost);
        
    }
    
    cout << min_cost << endl;
    
    
    return 0;
}
