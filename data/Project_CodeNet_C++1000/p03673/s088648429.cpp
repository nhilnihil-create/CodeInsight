#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    deque<int> d;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(i % 2) d.push_back(a);
        else d.push_front(a);
    }

    if(n % 2) {
        for(int i = 0; i < n; i++) {
            cout << d.front() << " ";
            d.pop_front();
        }
    } else {
        for(int i = 0; i < n; i++) {
            cout << d.back() << " ";
            d.pop_back();
        }
    }

    cout << endl;
}