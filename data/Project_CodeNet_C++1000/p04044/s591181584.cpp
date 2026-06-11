#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
 
int main(){
    int N, M;
    string A;
    scanf("%d %d", &N, &M);
    vector<string> a;
 
    while (N--){
        cin >> A;
        a.push_back(A);
    }
 
    sort(a.begin(), a.end());
 
    for (auto i : a)
        cout << i;
    cout << "\n";
}