#include<bits/stdc++.h>
using namespace std;

string X,ans;
stack<char> stc;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>X;
    for(int i = 0;i < X.length();i++){
        if(stc.empty()){
            stc.push(X[i]);
        }
        else if(!(stc.top() == 'S' && X[i] == 'T')){
            stc.push(X[i]);
        }
        else {
            stc.pop();
        }
    }
    cout<<stc.size()<<endl;
}
