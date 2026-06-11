#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define pye cout << "yes" << endl;
#define pno cout << "no" << endl;
#define pYe cout << "Yes" << endl;
#define pNo cout << "No" << endl;
#define pYE cout << "YES" << endl;
#define pNO cout << "NO" << endl;
#define prin(num) cout << num << endl;
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX_V 10005
#define MAX_E 30005
#define NIL -1
#define WHITE 0
#define BLACK 1
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll N;
ll a[300001];
ll sm[2][100001];

int main(void) {
    cin >> N;
    ll i;
    for(i=0; i<N*3; i++) {
        cin >> a[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>> pque1;
    for(i=0; i<N; i++) {
        sm[0][0]+=a[i];
        pque1.push(a[i]);
    }
    for(i=0; i<N; i++) {
        sm[0][i+1]=sm[0][i];
        sm[0][i+1]+=a[N+i];
        pque1.push(a[N+i]);
        sm[0][i+1]-=pque1.top();
        pque1.pop();
    }
    priority_queue<ll> pque2;
    for(i=0; i<N; i++) {
        sm[1][N]+=a[N*2+i];
        pque2.push(a[N*2+i]);
    }
    for(i=0; i<N; i++) {
        sm[1][N-1-i]=sm[1][N-i];
        sm[1][N-1-i]+=a[N*2-i-1];
        pque2.push(a[N*2-i-1]);
        sm[1][N-1-i]-=pque2.top();
        pque2.pop();
    }
    
    ll ans=-INF;
    for(i=0; i<=N; i++) {
        ans=max(ans, sm[0][i]-sm[1][i]);
    }
    
    prin(ans);
}