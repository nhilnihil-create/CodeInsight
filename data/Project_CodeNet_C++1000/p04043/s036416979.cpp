#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
 
int main(){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
 
    int count(0);
    if (A == 5) count++;
    if (B == 5) count++;
    if (C == 5) count++;
    if (count == 2){
        if (A == 7) count++;
        else if (B == 7) count++;
        else if (C == 7) count++;
    }
    else cout << "NO\n";
    if (count == 3) cout << "YES\n";
}