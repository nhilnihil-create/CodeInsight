#include <iostream>
#include <map>
using namespace std;

void solve()
{
    int N; cin >> N;
    map<long long,int> M;
    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        M[a]++;
    }
    long long x = 0,y = 0;
    while(!M.empty()){
        int k = M.rbegin()->first;
        if(M[k] >= 2) {
            x = k; 
            M[k] -= 2;
            break;
        }
        else M.erase(k);
    }
    while(!M.empty()){
        int k = M.rbegin()->first;
        if(M[k] >= 2) {
            y = k; break;
        }
        else M.erase(k);
    }
    cout << x*y << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}