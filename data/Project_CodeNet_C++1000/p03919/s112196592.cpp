#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int h, w, i_ans, j_ans;
    cin >> h >> w;
    string s;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> s;
            if(s == "snuke"){
                i_ans = i;
                j_ans = j;
            }
        }
    }
    string s_ans = "A";
    s_ans[0] += j_ans;
    cout << s_ans[0] << i_ans+1 << endl;
}
