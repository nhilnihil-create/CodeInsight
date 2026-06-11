#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[303][303];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> a[i][j];
        a[i][j]--;
    }
    int nth[303] {0};
    int deleted[303] {0};
    int ans = 1000;
    for(int count = 0; count < m; count++){
        int pop[303] {0};
        for(int i = 0; i < n; i++){
            while(deleted[a[i][nth[i]]]) nth[i]++;
            pop[a[i][nth[i]]]++;
        }
        int lar = 0;
        int larnum = -1;
        for(int i = 0; i < m; i++){
            if(pop[i] > lar){
                lar = pop[i];
                larnum = i;
            }
        }
        ans = min(ans, lar);
        deleted[larnum] = 1;
    }
    cout << ans << endl;
}