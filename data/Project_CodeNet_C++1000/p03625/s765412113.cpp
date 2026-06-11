#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    
    int N; cin >> N;
    int data[N],ans[2] ={0,0};
    for(int i=0;i<N;i++) cin >> data[i];
    sort(data,data+N,greater<int>());
    int index=0;
    for(int i=0;i<N-1;i++){
        if(data[i] == data[i+1]){ans[index] = data[i]; index++; i++;}
        if(index == 2) break;
    }
    cout << (ull)ans[0] * ans[1] << endl;
}