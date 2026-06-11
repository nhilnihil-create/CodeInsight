#include<bits/stdc++.h>
using namespace std;

int main() {
    vector <int> flag(8, 0);
    int N;
    int master = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        if (a<400) flag.at(0)=1;
        else if (a<800) flag.at(1)=1;
        else if (a<1200) flag.at(2)=1;
        else if (a<1600) flag.at(3)=1;
        else if (a<2000) flag.at(4)=1;
        else if (a<2400) flag.at(5)=1;
        else if (a<2800) flag.at(6)=1;
        else if (a<3200) flag.at(7)=1;
        else master++;
    }
    int min_ans = accumulate(flag.begin(), flag.end(), 0);
    int max_ans = min_ans+master;
    cout << max(1, min_ans) << " " << max_ans;
}