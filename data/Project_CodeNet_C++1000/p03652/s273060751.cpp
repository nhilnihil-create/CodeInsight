#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
using ll = long long int;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> wants(n, vector<int>(m, 0));
    vector<int> iter(n, 0);
    unordered_set<int> sports;
    for(int i=0; i<m; i++){
        sports.insert(i);
    }
    int want;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> want; want--; 
            wants[i][j] = want;
        }
    }
    // Debug
    // for(auto& people:wants){
    //     for(auto& v:people){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    int ans = n;
    for(int j=0; j<m; j++){
        vector<int> participants(m, 0);
        for(int i=0; i<n; i++){
            auto itr1 = sports.find(wants[i][iter[i]]);
            while(itr1 == sports.end()){
                iter[i]++;
                itr1 = sports.find(wants[i][iter[i]]);
            }
            participants[wants[i][iter[i]]]++;
        }
        auto itr2 = max_element(participants.begin(), participants.end());
        // for(auto& v:participants){
        //     cout << v << " ";
        // }
        // cout << "\n";
        // cout << "most famous:" << *itr2 << " " << itr2 - participants.begin() << endl;
        ans = min(ans, *itr2);
        sports.erase(itr2 - participants.begin());
    }
    cout << ans << endl;
    return 0;
}