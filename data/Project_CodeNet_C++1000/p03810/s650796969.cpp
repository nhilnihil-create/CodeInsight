#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

#define fi first
#define se second
typedef long long LL;
typedef long double LD;

int N,a[100010];

int gcd(int a, int b){
    if (!b) return a;
    return gcd(b,a%b);
}

bool get_ans(){
    int cnte=0,i,gc=0;
    bool g=1; LL sum=0;
    for (i=1; i<=N; i++){
        if (a[i]%2==0) cnte++;
        sum+=a[i];
        if (a[i]==1) g=0;
    }

    if (!g) return (sum-N)%2;

    if (cnte%2) return 1;
    else if (N-cnte>1) return 0;
    else {
        for (i=1; i<=N; i++){
            if (a[i]%2) a[i]--;
            gc=gcd(a[i],gc);
        }
        for (i=1; i<=N; i++)
            a[i]/=gc;

        return !get_ans();
    }
}
int main(){
    cin >> N;

    int i;
    for (i=1; i<=N; i++)
        cin >> a[i];

    bool ans=get_ans();
    if (ans) cout << "First\n";
    else cout << "Second\n";

    return 0;
}
