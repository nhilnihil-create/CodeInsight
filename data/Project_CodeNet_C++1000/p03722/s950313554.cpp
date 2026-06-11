#include<bits/stdc++.h>
 
using namespace std;
using S = set<long long>;
using D = deque<long long>; //pop_back pop_front push_back push_front front back clear empty
using L = vector<long long>;
using M = map<int,long long>;  //erase  (でキーごと削除) 追加削除検索O(log(N))
using A = vector<vector<long long>>;
using U = unordered_map<int,long long>; //map  (との違いはkeyの順番を保持していない)
using PQL = priority_queue<long long>; //erase  (でキーごと削除) push pop top 
using PQG = priority_queue<long long,L,greater<long long>>; //erase  (でキーごと削除) push pop top 

#define sorted(vector) sort(vector.begin(),vector.end()) //O(nlongn)
#define sortedreverce(vector) sort(vector.rbegin(),vector.rend()) //O(nlongn)
#define stablesorted(vector) stable_sort(vector.begin(), vector.end())
#define stablesortedreverce(vector) stable_sort(vector.rbegin(), vector.rend())
#define vdel(vector,a) vector.erase(vector.begin()+a)
#define vmin(vector) *min_element(vector.begin(),vector.end()) //O(N)
#define vmax(vector) *max_element(vector.begin(),vector.end()) //O(N)
#define vsum(vector) accumulate(vector.begin(),vector.end(),0) //O(N)
#define vcount(vector,a) count(vector.begin(), vector.end(),a) //O(N)
#define vfind(vector,a) find(vector.begin(), vector.end(), a) != vector.end() //遅いからあんまり使うな
#define bisect_left(vector,a) (lower_bound(vector.begin(),vector.end(),a)-vector.begin())
#define bisect_right(vector,a) (upper_bound(vector.begin(),vector.end(),a)-vector.begin())
#define max max<unsigned long>
#define min min<unsigned long>
#define inf 1000000000000000000+10
#define setans long long ans=0;

long long MOD=1000000007;

template <typename PQ>
long long pqsum(PQ pq){long long tmp=0;while(!pq.empty()){tmp+=pq.top();pq.pop();};return tmp;};

template <typename T>
void print(T a){for (auto b:a){cout<<b<<" ";};cout<<endl;}
template <>
void print(unsigned long a){cout<<a<<endl;}
template <>
void print(const char * a){cout<<a<<endl;}
template <>
void print(char a){cout<<a<<endl;}
template <>
void print(bool a){cout<<a<<endl;}
template <>
void print(double a){printf("%.16f",a);}
template <>
void print(long long a){cout<<a<<endl;}
template <>
void print(A a){for (auto b:a){for (auto c:b){cout<<c<<" ";}cout<<endl;};cout<<endl;}
template <>
void print(string a){cout<<a<<endl;}



//存在確認はmap!!!!!!!!!!!!!か配列に埋め込んでcontinueで回避
//__gcd(a,b)はコンパイラがGCC時のみ
//printf("%.16f", ans); 誤差落ち対応君


long long n,m;
vector<double> cost;
vector<int> negative;

void BELLMANFORD(long long point,long long n,A d){
    for(long long i=0  ;i<n+1  ;i++) cost.push_back(-numeric_limits<double>::infinity());
    cost[point]=0;
    for(long long i=0  ;i<n-1  ;i++){
        for(auto item_of_d:d){   //nownode nextnode passcost
            if (cost[item_of_d[1]]<cost[item_of_d[0]]+item_of_d[2]){
                cost[item_of_d[1]]=cost[item_of_d[0]]+item_of_d[2];
            }
        }
    }
    for(long long i=0  ;i<n+1  ;i++) negative.push_back(0);
    
    for(long long i=0  ;i<n  ;i++){
        for(auto item_of_d:d){   //nownode nextnode passcost
            if (negative[item_of_d[0]]){
                negative[item_of_d[1]]=1;
            }
            if (cost[item_of_d[1]]<cost[item_of_d[0]]+item_of_d[2]){
                cost[item_of_d[1]]=cost[item_of_d[0]]+item_of_d[2];
                negative[item_of_d[1]]=1;
            }
        }
    }
    
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    A d;
    long long tmp1,tmp2,tmp3;
    setans;
    cin>>n>>m;
    for(long long i=0  ;i<m  ;i++){
        cin>>tmp1>>tmp2>>tmp3;
        d.push_back({tmp1,tmp2,tmp3});
    }
    BELLMANFORD(1,n,d);
    
    if (negative[n]){
        print("inf");
    }else{
        ans=cost[n];
        print(ans);
    }
}


