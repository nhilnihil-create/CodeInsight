#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output3(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}
int MOD = pow(10, 9) + 7;



//今の時間よりも後の最速の便のインデックスを求める。
int search(vector<int> v,int time){
    return distance(v.begin(),lower_bound(v.begin(),v.end(),time));
}

bool check(string s){
    int n=s.length();
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]) return false;
    }
    return true;
}

signed main(){
    string s; cin>>s;
    int n=s.length();

    map<char,int> moji;
    for(int i=0;i<n;i++){
        moji[s[i]]++;
    }

    int ans=100;
   

    for(int i=0;i<26;i++){
        char choice='a'+i;
        if(moji[choice]==0)continue;
        string t=s;
        int cnt=0;

        while(check(t)==false){
            string t_dash="";
            for(int j=0;j<t.length()-1;j++){
                if(t[j]==choice||t[j+1]==choice) t_dash+=choice;
                else t_dash+=t[j];
            }
            t=t_dash;
            //cout<<t<<" "<<choice<<endl;
            cnt++;
        }

        ans=min(ans,cnt);
    }

    cout<<ans<<endl;

}