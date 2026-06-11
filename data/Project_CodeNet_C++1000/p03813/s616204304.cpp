#include<bits/stdc++.h>
# define    all(a)              a.begin(), a.end()
#define forn(i, a, b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define MOD int(1e9+7)
using namespace std;

typedef long long int ll;

bool cmp(int a, int b) {
    return a < b;
}

void printV(vector<int> nums) {
    for (int i: nums) {
        printf("%d ", i);// << " ";
    }
    printf("\n");
}

// void printV(vector<ll> nums) {
//     for (ll i: nums) {
//         printf("%lld ", i);// << " ";
//     }
//     printf("\n");
// }



int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int i, int j, int n, int m) {
    if (i >= 0 && i < n && j >=0 && j < m)
        return true;
    else 
        return false;
}

vector<int> seive(int n) {
    vector<int> prime;
    vector<bool> flag(n+1);
    int cnt = 0;
    for (int i=2; i<=n+1; i++) {
        cnt++;
        if (!flag[i]) {
            for (int j=2; j*i<=n; j++) {
                flag[i*j] = true;
                cnt++;
            }
        }
    }
    // cout << cnt << endl;
    for (int i=2; i<=n; i++)
        if (!flag[i])
            prime.pb(i);
    return prime;
}


int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    // time_t start, end;
    // time(&start);
    int n;
    cin >> n;
    if (n < 1200)
    cout << "ABC" << endl;
else
cout << "ARC" << endl;

    // printV(res);
    // time(&end); 
    // double time_taken = double(end - start);
    // cout << "Time Taken: " << fixed << time_taken << setprecision(5);
    // cout << " sec" << endl;
    return 0;
}      