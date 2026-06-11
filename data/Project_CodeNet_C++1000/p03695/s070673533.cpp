#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    set<int> color;
    int f_count = 0;

    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        if(a < 400) color.insert(1);
        else if(a < 800) color.insert(2);
        else if(a < 1200) color.insert(3);
        else if(a < 1600) color.insert(4);
        else if(a < 2000) color.insert(5);
        else if(a < 2400) color.insert(6);
        else if(a < 2800) color.insert(7);
        else if(a < 3200) color.insert(8);
        else if(a >= 3200) f_count++;
    }

    int min_color = max(int(color.size()), 1);
    int x = f_count + color.size();
    int max_color = x;
    cout << min_color << " " << max_color;
}