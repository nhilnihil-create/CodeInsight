#include <cstdio>
#include <map>
using namespace std;

const int MAX = 1e5+10;
int a[MAX];
map<int, int> mp;

int main(){
    mp.clear();
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        mp[a[i]]++;
        mp[a[i]-1]++;
        mp[a[i]+1]++;
    }
    int k = 0, mx = 0;
    for (int i = -1; i < MAX; i++){
        if (mp[i] > mx){
            mx = mp[i];
            k = i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i]==k || a[i]+1==k || a[i]-1==k) cnt++;
    printf("%d\n", cnt);
    return 0;
}
