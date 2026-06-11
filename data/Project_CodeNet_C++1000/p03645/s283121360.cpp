#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n, m;
    cin >> n >> m;
    long int a, b, chk = 0;
    vector<long int>cnct_a;
    vector<long int>cnct_b;
    for(long int i = 0; i < m; i++){
        cin >> a >> b;
        if(a == 1 && b == n){
            chk = 1;
            break;
        }
        else{
            if(a == 1)
                cnct_a.push_back(b);
            if( b == n)
                cnct_b.push_back(a);
        }
    }
    sort(cnct_a.begin(), cnct_a.end());
    sort(cnct_b.begin(), cnct_b.end());

    if(chk == 0){
        if(cnct_a.size() == 0 || cnct_b.size() == 0)
            chk = 0;
        else{
            vector<long int>v(cnct_a.size() + cnct_b.size());
            vector<long int>::iterator it, st;
            it = set_intersection(cnct_a.begin(), cnct_a.end(), cnct_b.begin(), cnct_b.end(), v.begin());

            for (st = v.begin(); st != it; ++st){
                chk = 1;
                break;
            }
        }
    }
    if(chk == 0)
        cout << "IMPOSSIBLE";
    else if(chk == 1)
        cout << "POSSIBLE";

    return 0;
}
