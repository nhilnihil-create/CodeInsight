#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int N,M,a[100010],K,b[100010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    int i,odd=0;
    for (i=1; i<=M; i++){
        cin >> a[i];
        if (a[i]%2) odd++;
    }

    if (odd>2){
        cout << "Impossible\n";
        return 0;
    }

    sort(a+1,a+M+1,[](int x, int y){return x%2<y%2; });
    if (a[M-1]%2) swap(a[1],a[M-1]);
    for (i=1; i<=M; i++)
        cout << a[i] << " ";
    cout << "\n";

    if (M==1){
        if (a[1]==1) K=1,b[1]=1;
        else K=2,b[1]=a[1]-1,b[2]=1;
    }
    else {
        b[++K]=a[1]+1;
        for (i=2; i<M; i++)
            b[++K]=a[i];
        if (a[M]!=1) b[++K]=a[M]-1;
    }

    cout << K << "\n";
    for (i=1; i<=K; i++)
        cout << b[i] << " ";
    cout << "\n";
    return 0;
}
