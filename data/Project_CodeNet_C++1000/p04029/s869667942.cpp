#include<bits/stdc++.h>
using namespace std;
#define rep(i, V) for (int i = 0; i < V; i++)
#define _GLIBCXX_DEBUG

int sum(int n){
    if (n==1){
        return 1;
    }else{
        return n + sum(n-1);
    }
}

int main(){
    int a;
    cin >> a;
    cout << sum(a);
}