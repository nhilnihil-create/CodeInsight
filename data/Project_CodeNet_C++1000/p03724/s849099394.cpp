#include<bits/stdc++.h>
using namespace std;

//typedef
typedef long long LL;
typedef unsigned int UINT;
typedef unsigned long long ULL;
typedef set<int, greater<int> > setdownINT;
typedef set<long long, greater<long long> > setdownLL;
typedef priority_queue<int, vector<int>, greater<int> > priqueupINT;
typedef priority_queue<long long, vector<long long>, greater<long long> > priqueupLL;
//container utill
#define ALL(v) (v).begin(),(v).end()
#define sortdown(v) sort((v).begin(),(v).end()), reverse((v).begin(),(v).end())
#define PB(a) push_back(a)
#define MP make_pair
#define MT make_tuple
//constant
#define PI 3.141592653589793

int main(){
    //input
    int N, M;
    cin >> N >> M;
    int counta[N];
    fill(counta,counta+N,0);
    int a,b;
    int i;
    for(i=1; i<=M; i++){
        cin >> a >> b;
        a--;
        b--;
        counta[a]++;
        counta[b]++;
    }

    //calc
    for(i=0; i<N; i++){
        if(counta[i]%2==1){
            cout << "NO" << endl;
            system("pause");
            return 0;
        }
    }
    
    cout << "YES" << endl;
    system("pause");
    return 0;
}