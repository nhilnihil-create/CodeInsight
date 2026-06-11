#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string A;
int Path[26][200010];
int From[200010];
string ans;

void dp(){
    A = "#" + A;
    int L = A.size();
    for(int i = 0; i < 26; i++){
        Path[i][L-1] = 200005;
        for(int j = L-1; j > 0; j--){
            if(A[j] - 'a' == i)Path[i][j-1] = j;
            else Path[i][j-1] = Path[i][j];
        }
    }
}

void bfs(){
    for(int i = 0; i < 200010; i++)From[i] = -1;
    queue<int>Q;
    Q.push(0);
    while(true){
        int pos = Q.front();
        Q.pop();
        if(pos == 200005)break;
        for(int i = 0; i < 26; i++){
            if(From[Path[i][pos]] != -1)continue;
            From[Path[i][pos]] = pos;
            Q.push(Path[i][pos]);
        }
    }
}

void backtrack(){
    ans = "";
    for(int pos = 200005; pos; pos = From[pos]){
        for(int i = 0; i < 26; i++){
            if(Path[i][From[pos]] == pos){
                ans += string(1, 'a'+i);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
}

int main(){
    cin >> A;
    dp();
    bfs();
    backtrack();
    cout<<ans<<endl;
    return 0;
}