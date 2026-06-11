#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0;i < n;i++){
        cin >> p[i];
        p[i]--;
    }

    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0;i < n;i++){
        a[i] = n * (i + 1);
        b[i] = n * (n - i);
    }

    for(int i = 1;i < n;i++){
        b[p[i]] += i;
    }

    for(int i = 0;i < n;i++)cout << a[i] << ' ';
    cout << '\n';
    for(int i = 0;i < n;i++)cout << b[i] << ' ';
    cout << '\n';
}
