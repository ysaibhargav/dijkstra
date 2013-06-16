#include <iostream>
#include <vector>
#include <map>
#define N 0x7fffffff;
#define w(u, v) G[u][v].second;

using namespace std;

typedef vector<vector <pair<int, int> > > graph;
typedef vector<int> list;
typedef pair<int, int> p;

class Heap{
	private:
		int n;
		p A[1025];
		map<int, int> M;
	public:
		Heap(){
			n = 0;
			for(int i = 0; i < 1025; i++){
				A[i].second = -1;
			}
		}
		Heap emptyQ(){
			return Heap();
		}
		void decreaseKey(int n_, int k){
			int x = M[n_];
			int parent_x = x/2;
			A[x].second = k;
			while (parent_x != 0 && k < A[parent_x].second){
				p T = A[x];
				A[x] = A[parent_x];
				M[A[parent_x].first] = x;
				A[parent_x] = T;
				M[n_] = parent_x;
			}	
		}
		void increaseKey(int n_, int k){
                        int x = M[n_], lC = A[2*x].second, rC = A[2*x+1].second;
                        A[x].second = k;
                        while (lC != -1 || rC != -1){
                                p T = A[x];
				if(lC < rC || rC == -1){
					A[x] = A[2*x];
					M[A[2*x].first] = x;
					A[2*x] = T;
					M[n_] = 2*x;	
					x = 2*x;
					lC = A[2*x].second, rC = A[2*x+1].second;
				}
				else{
					A[x] = A[2*x+1];
					M[A[2*x+1].first] = x;
					A[2*x+1] = T;
					M[n_] = 2*x+1;	
					x = 2*x+1;
					lC = A[2*x].second, rC = A[2*x+1].second;
				}		
                        }
                }
		void insert(int n_, int k){
			n++;
			A[n] = make_pair(n_, k);
			M.insert(make_pair(n_, n));
			decreaseKey(n_, k);	
		}
		p extractMin(){
			p min = A[1];
			A[1] = A[n];
			A[n].second = -1;
			n--;
			increaseKey(A[1].first, A[1].second);
			return min;
		}
		bool isEmpty(){
			if(n == 0)	return true;
			else	return false;
		}
		int size(){
			return n;
		}
};

void disp(list A){
	for(int i = 0; i < A.size(); i++){
		cout << i << " --> " << A[i] << endl;
	}
}

list Dijkstra(graph G, int S){
	int inf = N;
	list dist(G.size(), inf);
	dist[S] = 0;
	Heap Q = Heap();
	Q.insert(0, 0);
	int n = G.size();
	for(int i = 1; i < n; i++){
		Q.insert(i, inf);	
	}
	while (!Q.isEmpty()){
		int u, min = N;
		p T = Q.extractMin();
		u = T.first, min = T.second;
		if(min == inf)	break;

		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].first;
			int alt = dist[u] + w(u, i);
			if(alt < dist[v]){
				dist[v] = alt;
				Q.decreaseKey(v, alt);
			}
		}
	}
	return dist;
}

main(){
	graph G;
	int S = 0, n, i = 0;
	cin  >> n;
	G.resize(n);
	while(i < n){
		int m;
		cin >> m;
		while(m-- > 0){
			int v, w;
			cin >> v >> w;
			G[i].push_back(make_pair(v, w));
		}
		i++;
	}
	list dist = Dijkstra(G, S);
	disp(dist);
}
