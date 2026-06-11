#include<iostream>
#include<cstdio>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> pos[26], pos_cnt[26]={};
int main(){
    string A;
    cin >> A;
    unordered_set<char> st;
    int ks[200000];
    int k = 0;

    for(int i = A.length() - 1; i >= 0; i--){
        st.insert(A[i]);
        ks[i] = k;
        if(st.size() == 26){
            k++;
            st.clear();
        }
     }
    for(int i = 0; i < A.length(); i++){
        pos[A[i]-'a'].push_back(i);
    }

    /*
    cout << k << endl;
    for(int i = 0; i < A.length(); i++){
        cout << ks[i] << " ";
    }
    cout << endl;
    */
    /*
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < pos[i].size(); j++){
            cout << pos[i][j] << " ";
        }
        cout << endl;
    }
    */


    string ans;
    int start = 0;
    for(int i = 0; i < k + 1; i++){
        for(char c = 'a'; c <= 'z'; c++){
            auto itr = lower_bound(pos[c-'a'].begin(), pos[c-'a'].end(), start);
            //cout << *itr  << ", " << ks[*itr] << endl;
            //cout << (itr == pos[c-'a'].end())  << endl;
            //cout << itr - pos[c-'a'].begin() << endl;
            if((itr == pos[c-'a'].end()) || (ks[*itr] == k - i - 1)){
                //cout << "in" << endl;
                ans.push_back(c);
                //cout << "pushed" << endl;
                if(itr != pos[c-'a'].end()){
                    start = *itr + 1;
                }
                break;
            }
        }
    }
    cout << ans << endl;
}
