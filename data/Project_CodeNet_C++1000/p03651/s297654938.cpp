// AGC 18 A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main(){
    int n,k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    if(k > a[n-1]){
        cout << "IMPOSSIBLE" << endl; return 0;
    }
    int G = a[0];
    for(int i = 1; i < n; i++){
        G = gcd(G,a[i]);
    }
    if(k%G == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}