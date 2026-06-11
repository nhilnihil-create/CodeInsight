#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;

template <class T1, class T2>
using dict = std::unordered_map<T1, T2>;

int main(){
    int N;
    cin >> N;
    if (N%10==9 || (int)(N/10)==9) cout << "Yes" << endl;
    else cout << "No" << endl;
}