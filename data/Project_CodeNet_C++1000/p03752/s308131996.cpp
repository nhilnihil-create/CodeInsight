#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K,maxx;
    int64_t ans = 9223372036854775807,count;
    
    cin >> N>> K;
    vector<int> a(N);
    vector<int> a2(N);
    for(int i=0;i<N;i++)
        cin >> a.at(i);
    for (int bit = 0; bit < (1<<(N-1)); ++bit) {
        vector<int> S;
        count=0;
        a2=a;
        for (int i = 0; i < N-1; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i+1);
            }
        }
        if((int)S.size()!=K-1)
            continue;
        for (int i = 0; i < (int)S.size(); ++i) {
            maxx = *std::max_element(a2.begin(), a2.begin()+S.at(i));
            if(maxx>=a2.at(S.at(i))){
                count+=maxx-a2.at(S.at(i))+1;
                a2.at(S.at(i))+=maxx-a2.at(S.at(i))+1;
            }

        }
        ans=min(ans,count);
        /*for(int i=0;i<N;i++)
            cout << ifa.at(i) <<" ";
        cout << count <<endl;
        */
    }
    if(9223372036854775807==ans)
        ans =0;
    cout << ans <<endl;
    
}