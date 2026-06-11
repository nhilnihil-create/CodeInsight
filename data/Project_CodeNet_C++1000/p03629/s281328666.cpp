#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main(){
    string s;
    cin >> s;
    string ans[26];
    for (int i = 0; i < 26;i++){
        ans[i] += ('a' + i);
    }
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i] - 'a';
        string minstr = ans[0];
        for (int j = 1; j < 26; j++)
        {
            if(minstr.size()>ans[j].size()){
                minstr = ans[j];
            }
            else if(minstr.size() == ans[j].size()){
                if(minstr>ans[j]){
                    minstr = ans[j];
                }
            }
        }
        ans[x] = minstr;
        ans[x] += s[i];
    }
    string minstr;
    minstr = ans[0];
    for (int i = 1; i < 26; i++)
    {
        if(minstr.size()>ans[i].size()){
            minstr = ans[i];
        }
        else if(minstr.size() == ans[i].size()){
            if(minstr>ans[i]){
                minstr = ans[i];
            }
        }
    }
    cout << minstr << endl;
    return 0;
}
