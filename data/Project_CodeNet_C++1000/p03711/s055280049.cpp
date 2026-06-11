#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;

int main(){
    int a[] = {1, 3, 5, 7, 8, 10, 12};
    int b[] = {4, 6, 9, 11};
    int m, n;
    cin >> m >> n;
    if(m == 2 || n == 2){
        cout << "No";
    }
    else{
        if(!(binary_search(a, a+7, m) ^ binary_search(a, a+7, n))){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
    }
    return 0;
}