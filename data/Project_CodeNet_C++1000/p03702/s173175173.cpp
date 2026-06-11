#include <bits/stdc++.h>
using namespace std;

long long int rightt=1000000009; long long int lefft=0;
long long int n, a, b;
long long int vec[111111];

void bin(){
    long long int mid=(rightt+lefft)/2;
    long long int ans=b*mid, sum=0;
    for(int i=0;n>i;i++){
        sum+=max(0LL, (vec[i]-ans+(a-b-1))/(a-b));
    }
    if(sum>mid){
        lefft=mid;
    }
    else{
        rightt=mid;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;
    for(int i=0;n>i;i++){
        cin >> vec[i];
    }
    while(rightt-lefft>1){
        bin();
    }
    cout << rightt;
}
