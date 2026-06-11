#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N; cin >> N;
    int p[N];
    for(int i=0;i<N;i++){
        cin >> p[i]; p[i]--;
    }
    int a[N];
    int b[N];
    int r[N];
    for(int i=0;i<N;i++){
        r[p[i]]=i+1;
    }
    for(int i=0;i<N;i++){
        a[i]=N*(i+1);
        b[i]=N*(N-i-1)+r[i];
    }
    
    for(int i=0;i<N;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0;i<N;i++){
        cout << b[i] << " ";
    }
    cout << endl;
    
}