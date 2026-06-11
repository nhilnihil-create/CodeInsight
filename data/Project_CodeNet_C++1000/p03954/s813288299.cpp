#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
int bottom[200001];

bool top(int x){
    for(int i=1;i<N;i++){
        if((bottom[N-1+i]>=x)==(bottom[N-1+i-1]>=x)) return bottom[N-1+i]>=x;
        if((bottom[N-1-i]>=x)==(bottom[N-1-i+1]>=x)) return bottom[N-1-i]>=x;
    }
    return (bottom[0]>=x);
}

int main(){
    cin >> N;
    for(int i=0;i<2*N-1;i++){
        cin >> bottom[i];
    }
    int l=1,r=2*N;
    while(r-l>1){
        int m=(l+r)/2;
        if(top(m)) l=m;
        else r=m;
    }
    cout << l << endl;
    
    return 0;
}