#include"queue.h"
#include<iostream>
#include"Vector.h"
#include"priority_queue.h"
#include"stack.h"

using namespace std;

template<typename T>
class graph {
private:
	class Edge {
	public:
		float weight;
		int to;
		int from;

		Edge() : weight(0), to(-1), from(-1) {}  // 默认构造函数
		Edge(float w, int t, int f) {
			weight = w;
			to = t;
			from = f;
		}
		bool operator<(const Edge& other)const {
			return weight < other.weight;
		}
		bool operator>(const Edge& other)const {
			return weight > other.weight;
		}
		friend class graph<T>;
		friend class priority_queue<T>;
	};
	my_vector<my_vector<Edge>>adjlist;

public:
	graph(int num_vertices) {
		my_vector<Edge> edge = my_vector<Edge>();
		adjlist = my_vector<my_vector<Edge>>(num_vertices, edge);
	}

	float get_weight(Edge myedge) {
		return myedge.weight;
	}
	int get_to(Edge myedge) {
		return myedge.to;
	}

	void addedge(int f, int t, float w) {
		if (f >= 0 && f < adjlist.getsize() && t >= 0 && t < adjlist.getsize()) {
			Edge newedge(w, t, f);
			adjlist[f].push_back(newedge);
			// 添加反向边的代码（对于无向图）
		}
	}
	void add_vertex() {
		adjlist.push_back(my_vector<Edge>());
	}

	int count_edge() {
		int count = 0;
		for (int i = 0; i < adjlist.getsize(); i++) {
			count += adjlist[i].getsize();
		}
		return count;
	}
	int count_vatex() {
		return adjlist.getsize();
	}
	void bfs() {
		my_vector<bool>vis(adjlist.getsize(), false);
		queue<int>tovis;
		tovis.push(0);
		vis[0] = true;

		while (!tovis.isempty()) {
			int to_visnow = tovis.top(); tovis.pop();
			cout << to_visnow << "\n";
			for (int i = 0; i < adjlist[to_visnow].getsize(); i++) {
				if (vis[get_to(adjlist[to_visnow][i])] == false) {
					tovis.push(get_to(adjlist[to_visnow][i]));
					vis[get_to(adjlist[to_visnow][i])] = true;
				}
			}
		}
	}
	void dfs(int start_vertex) {
		if (start_vertex < 0 || start_vertex >= adjlist.getsize()) {
			throw std::invalid_argument("Start vertex is out of bounds.");
		}

		my_vector<bool> visited(adjlist.getsize(), false);
		stack<int> to_visit;
		to_visit.push(start_vertex);

		while (!to_visit.isempty()) {
			int current = to_visit.top();
			to_visit.pop();

			if (!visited[current]) {
				cout << current << "\n";
				visited[current] = true;

				for (int i = adjlist[current].getsize() - 1; i >= 0; --i) {
					int neighbor = adjlist[current][i].to;
					if (!visited[neighbor]) {
						to_visit.push(neighbor);
					}
				}
			}
		}
	}


	my_vector<int> dijkstra(int src) {
		my_vector<int> dis(count_vatex(), INT_MAX);
		my_vector<bool> vis(count_vatex(), false);
		priority_queue<Edge> pq;
		dis[src] = 0;

		pq.push(Edge(0, src, src)); // 初始边，权重为 0
		while (!pq.isempty()) {
			Edge e = pq.top();
			int v = e.to;
			pq.pop();

			if (vis[v]) continue;
			vis[v] = true;

			for (int i = 0; i < adjlist[v].getsize(); i++) {
				Edge& adjEdge = adjlist[v][i];
				int to = adjEdge.to;
				float weight = adjEdge.weight;

				if (!vis[to] && dis[v] + weight < dis[to]) {
					dis[to] = dis[v] + weight;
					pq.push(adjEdge);
				}
			}
		}
		return dis;
	}
	int get_mindis(int src, int to) {
		return dijkstra(src)[to];
	}
};
