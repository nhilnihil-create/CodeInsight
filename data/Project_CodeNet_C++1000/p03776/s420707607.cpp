#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, a, b, cnt = 0;
    vector<long long> v;
    vector< vector<long long> > c;
    long long sum = 0, num = 0;
    cin >> n >> a >> b;
    v.assign(n, 0);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<long long>());
    for(int i=0;i<a;i++) sum += v[i];
    for(int i=0;i<n;i++){
        if(v[i] == v[a-1]) cnt++;
    }
    c.assign(cnt+1, vector<long long>());
    for(int i=1;i<=cnt;i++){
        c[i].assign(i+1, 1);
        for(int j=1;j<i;j++){
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    int d = 0;
    for(int i=0;i<b;i++){
        if(v[i] == v[a-1]) d++;
        if(i >= a && v[i] != v[0]) break;
        if(i >= a-1) num += c[cnt][d];
    }
    cout << fixed << setprecision(8) << (double) sum / a << endl;
    cout << num << endl;
	return 0;
}