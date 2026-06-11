
#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <bitset>

using namespace std;
const int64_t INF=10000000000000000;
template<class T>
void read_1d(std::vector<T>& a,int64_t num){
	a.reserve(num);
	for(int64_t i1=0;i1<num;i1++){
		T temp;
		cin>>temp;
		a.push_back(temp);
	}
}
template<class T>
void read_2d(std::vector<std::vector<T> >&a,int64_t x,int64_t y ){
	a.resize(x);
	for(int64_t i1=0;i1<x;i1++){
		a[i1].reserve(y);
		for(int64_t i2=0;i2<y;i2++){
			T temp;
			cin>>temp;
			a[i1].push_back(temp);
		}
	}
}
template<class InputIterator>
void debug(InputIterator first,InputIterator last){
	for(auto i1=first;i1!=last;i1++){
		cout<<(*i1)<<endl;
	}
}
#include <limits>
#include <vector>
#include <queue>
class Vertex;
class Edge{
public:
	friend class Vertex;
	friend class Graph;
	Vertex* from;
	Vertex* to;
	int64_t cost;
public:
	Edge(Vertex* from,Vertex* to,int64_t cost=0){
		this->from=from;
		this->to=to;
		this->cost=cost;
	}

};
struct Dijkstra{
	int64_t d;
	Vertex* parent;
	bool searched;
};

class Vertex{
	friend class Graph;
public:

	std::vector<Edge*> departure;
	std::vector<Edge*> arrival;
	bool searched=false;

	Dijkstra dijk_data;
	int32_t id;
	bool count_finish=false;
	void add_edge(Edge* d){
		departure.push_back(d);
		d->to->arrival.push_back(d);
	}
	void initialize_Dijkstra(){
		dijk_data.d=std::numeric_limits<int64_t>::max();
		dijk_data.parent=NULL;
		dijk_data.searched=false;
	}
	int32_t count_union(Edge* e1,Edge* e2){
		int32_t retval=1;
		count_finish=true;
		for(auto i1=departure.begin();i1!=departure.end();i1++){
			Edge *temp=(*i1);
			if(temp==e1||temp==e2||temp->to->count_finish){
				continue;
			}
			retval+=temp->to->count_union(e1,e2);
		}
		return retval;
	}
	uint64_t game(){
		searched=true;
		uint64_t size=0;
		uint64_t xor_num=0;
		uint64_t c_ans;
		for(auto i1=departure.begin();i1!=departure.end();i1++){
			Edge *temp=(*i1);
			if(!temp->to->searched){
				size++;
				c_ans=temp->to->game()+1;
				xor_num=xor_num^c_ans;
			}
		}
		if(size==0){
			return 0;
		}else if(size==1){
			return c_ans;
		}else{
			return xor_num;
		}
	}
};
class dijkstra_calc{
public:
	int64_t current_cost;
	Vertex* from;
	Vertex* to;
	dijkstra_calc(const int64_t cost, Vertex* c1,Vertex* c2):current_cost(cost),from(c1),to(c2){

	}
};
bool operator<(const dijkstra_calc& a,const dijkstra_calc& b){
	return a.current_cost<b.current_cost;
}
bool operator>(const dijkstra_calc& a,const dijkstra_calc& b){
	return a.current_cost>b.current_cost;
}


class Graph{
private:
	std::vector<Vertex*> v;
	std::vector<Edge*> e;
	int64_t **WF;
	void initialize_Dijkstra(){
		for(auto i=v.begin();i!=v.end();i++){
			Vertex *temp=(*i);
			temp->initialize_Dijkstra();
		}
	}
	static void dijkstra(Vertex* source,Vertex* goal=NULL){
		std::priority_queue<dijkstra_calc,std::vector<dijkstra_calc>,std::greater<dijkstra_calc> > queue;
		queue.push(dijkstra_calc(0,NULL,source));
		while(true){
			const dijkstra_calc temp=queue.top();
			queue.pop();
			if(!(temp.to->dijk_data.searched)){
				temp.to->dijk_data.searched=true;
				temp.to->dijk_data.parent=temp.from;
				temp.to->dijk_data.d=temp.current_cost;

				for(auto i=temp.to->departure.begin();i!=temp.to->departure.end();i++){
					const Edge *j=(*i);
					if(!j->to->dijk_data.searched){
						dijkstra_calc a(temp.current_cost+(j->cost),j->from,j->to);
						queue.push(a);
					}
				}
				if(temp.to==goal){
					return;
				}
			}
			if(queue.empty()){
				return;
			}
		}
	}
public:
	static const int64_t INF=1000000000000000;
	Graph(int32_t num_v){
		v.reserve(num_v);
		for(int32_t i1=0;i1<num_v;i1++){
			Vertex* temp=new Vertex();
			temp->id=i1;
			v.push_back(temp);
		}
		/*WF=new int64_t*[num_v];
		for(int64_t i1=0;i1<num_v;i1++){
			WF[i1]=new int64_t[num_v];
		}*/
	}
	void add_edge(int32_t from,int32_t to,int32_t cost=0){
		Edge *temp=new Edge(v[from],v[to],cost);
		e.push_back(temp);
		v[from]->add_edge(temp);
	}
	void dijkstra(int32_t start){
		initialize_Dijkstra();
		dijkstra(v[start]);
	}
	void dijkstra(int32_t start,int32_t goal){
		initialize_Dijkstra();
		dijkstra(v[start],v[goal]);
	}
	int64_t** WarshallFloid(){
		for(int64_t i1=0;i1<v.size();i1++){
			for(int64_t i2=0;i2<v.size();i2++){
				WF[i1][i2]=INF;
			}
		}
		for(int64_t i1=0;i1<v.size();i1++){
			for(auto i2=v[i1]->departure.begin();i2!=v[i1]->departure.end();i2++){
				Edge *temp=(*i2);
				if(WF[i1][temp->to->id]>temp->cost){
					WF[i1][temp->to->id]=temp->cost;
				}
			}
			WF[i1][i1]=0;
		}
		for(int64_t i1=0;i1<v.size();i1++){
			for(int64_t i2=0;i2<v.size();i2++){
				for(int64_t i3=0;i3<v.size();i3++){
					WF[i2][i3]=min(WF[i2][i3],WF[i2][i1]+WF[i1][i3]);
				}
			}
		}
		return WF;
	}
	Vertex* getVertex(int place) const{
		return v[place];
	}
	bool isBridge(Edge* e1,Edge* e2){
		for(auto i1=v.begin();i1!=v.end();i1++){
			Vertex* temp=(*i1);
			temp->count_finish=false;
		}
		int32_t r=v[0]->count_union(e1,e2);
		return v.size()!=r;
	}
	vector<Edge*> getEdge(){
		return e;
	}
	virtual ~Graph(){
		for(auto i=v.begin();i!=v.end();i++){
			delete *i;
		}
		for(auto i=e.begin();i!=e.end();i++){
			delete *i;
		}
		/*for(int64_t i1=0;i1<v.size();i1++){
			delete[] WF[i1];
		}
		delete[] WF;*/
	}
};
int main(){
	int64_t n;
	cin>>n;
	Graph graph(n);
	for(int64_t i1=0;i1<n-1;i1++){
		int64_t temp1,temp2;
		cin>>temp1>>temp2;
		graph.add_edge(temp1-1,temp2-1);
		graph.add_edge(temp2-1,temp1-1);
	}

	if(graph.getVertex(0)->game()==0){
		cout<<"Bob"<<endl;
	}else{
		cout<<"Alice"<<endl;
	}

}