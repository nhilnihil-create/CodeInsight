#include <bits/stdc++.h>
#define MAXN 200100
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e9 + 7;
int roads[MAXN], rails[MAXN];
map <pii, int> freq;

int find_road(int i){
    return roads[i] = (i == roads[i]? i : find_road(roads[i]));
}
int find_rail(int i){
    return rails[i] = (i == rails[i]? i : find_rail(rails[i]));
}
void merge_road(int a, int b){
    int fa = find_road(a);
    int fb = find_road(b);

    if (fa != fb){
        roads[fb] = fa;
    }
}

void merge_rail(int a, int b){
    int fa = find_rail(a);
    int fb = find_rail(b);

    if (fa != fb){
        rails[fb] = fa;
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    int a ,b;
    char op;

    cin >> a >> op >> b;

    cout << (op == '+'? a+b : a-b) << endl;
    return 0;
}