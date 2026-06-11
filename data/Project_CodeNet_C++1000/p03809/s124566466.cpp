#include <iostream>
#include <vector>
using namespace std;
int n, a[100000];
vector<int> v[100000];
long long f(int x, int y){
    long long s = 0, b;
    if(v[x].size() == 1)return a[x];
    for(int i=0;i<v[x].size();i++){
        int z = v[x][i];
        if(z != y){
            long long w = f(z, x);
            if(w <= -1)return -1;
            s += w;
            if(w > a[x])return -1;
        }
    }
    if(y == -1){
        if((long long)a[x]*2 == s)return 1;
        return -1;
    }
    b = a[x]*2 - s;
    if(b > a[x])return -1;
    return b;
}
int main() {
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(n == 2){
        if(a[0] == a[1])puts("YES");
        else puts("NO");
        return 0;
    }
    for(int i=0;i<n;i++){
        if(v[i].size() > 1){
            long long w = f(i, -1);
            if(w == 1)puts("YES");
            else puts("NO");
            return 0;
        }
    }
	return 0;
}
