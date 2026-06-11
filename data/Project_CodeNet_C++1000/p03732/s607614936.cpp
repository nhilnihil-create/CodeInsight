#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, w;
    cin >> n >> w;
    int w1, v1;
    cin >> w1 >> v1;
    vector<int> nap1;
    vector<int> nap2;
    vector<int> nap3;
    vector<int> nap4;
    nap1.push_back(v1);
    long long w_base = w1;
    for (int i = 1; i < n; i++){
        cin >> w1 >> v1;
        if (w1 == w_base) nap1.push_back(v1);
        else if (w1 == w_base + 1) nap2.push_back(v1);
        else if (w1 == w_base + 2) nap3.push_back(v1);
        else nap4.push_back(v1);
    }
    sort(nap1.begin(), nap1.end(), greater<int>());
    sort(nap2.begin(), nap2.end(), greater<int>());
    sort(nap3.begin(), nap3.end(), greater<int>());
    sort(nap4.begin(), nap4.end(), greater<int>());
    int k1 = (int)nap1.size();
    int k2 = (int)nap2.size();
    int k3 = (int)nap3.size();
    int k4 = (int)nap4.size();
    vector<long long> acc_nap1(k1 + 1, 0);
    vector<long long> acc_nap2(k2 + 1, 0);
    vector<long long> acc_nap3(k3 + 1, 0);
    vector<long long> acc_nap4(k4 + 1, 0);
    for (int i = 0; i < k1; i++) acc_nap1[i+1] = acc_nap1[i] + nap1[i];
    for (int i = 0; i < k2; i++) acc_nap2[i+1] = acc_nap2[i] + nap2[i];
    for (int i = 0; i < k3; i++) acc_nap3[i+1] = acc_nap3[i] + nap3[i];
    for (int i = 0; i < k4; i++) acc_nap4[i+1] = acc_nap4[i] + nap4[i];

    long long ans = 0;

    for (int s1 = 0; s1 <= k1; s1++){
        for (int s2 = 0; s2 <= k2; s2++){
            for (int s3 = 0; s3 <= k3; s3++){
                for (int s4 = 0; s4 <= k4; s4++){
                    if (w_base * (s1 + s2 + s3 + s4) + s2 + s3 *2 + s4 * 3 <= w){
                        ans = max(ans, (acc_nap1[s1] + acc_nap2[s2] + acc_nap3[s3] + acc_nap4[s4]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}