#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int a,b,c,d,e,f; 
void input()
{
    cin >> a >> b >> c >> d >> e >> f;
}

void solve()
{
    vector<int> water(31,0),sugar(3001,0);
    water[a] = 1, water[b] = 1;
    sugar[0] = 1;
    for (int i = 0; i < 31; ++i) {
        if(water[i] == 1){
            if(i+a<31) water[i+a] = 1;
            if(i+b<31) water[i+b] = 1;
        }
    }
    for (int i = 0; i < 3001; ++i) {
        if(sugar[i] == 1){
            if(i+c<3001) sugar[i+c] = 1;
            if(i+d<3001) sugar[i+d] = 1;
        }
    }

    int ans[2]; 
    ans[0] = a*100, ans[1] = 0;
    for (int i = 1; i < 31; ++i) {
        if (water[i] == 0) continue;
        for (int j = 0; j < 3001; ++j) {
            if (sugar[j] == 0) continue;
            if (i * e < j) continue;
            if (i * 100 + j > f) continue;

            if ((i * 100 + j) * ans[1] < j * ans[0]){
                ans[0] = i * 100 + j, ans[1] = j;
            }
        }
    }
    cout << ans[0] << " " << ans[1] << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}