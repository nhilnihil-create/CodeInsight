#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int Path[26][200010];
int From[200010];
string A;
void dp(){
    for(int i=0;i<200010;i++)From[i] = -1;
    A = "#" + A;
    int L = A.size();
    for(int i=0;i<26;i++){
        Path[i][L-1] = 200005;
        for(int j = L-1;j>0;j--){
            if(A[j]-'a'==i)Path[i][j-1] = j;
            else Path[i][j-1] = Path[i][j];
        }
    }
}
int main(){
    cin>>A;
    dp();
    queue<int>fromQ, toQ;
    fromQ.push(0);
    toQ.push(0);
    while(true){
        int from = fromQ.front(); fromQ.pop();
        int to = toQ.front(); toQ.pop();
        if(From[to]!=-1)continue;
        From[to] = from;
        if(to == 200005)break;
        for(int i=0;i<26;i++){
            if(From[Path[i][to]]!=-1)continue;
            fromQ.push(to);
            toQ.push(Path[i][to]);
        }
    }
    string ans = "";
    for(int i=200005;i;i = From[i]){
        for(int j=0;j<26;j++){
            if(Path[j][From[i]]==i){
                ans += string(1, 'a'+j);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}