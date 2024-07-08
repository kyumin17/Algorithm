#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[N];
bool visit[N];

void DFS(int v) {
	visit[v] = true;
	cout << v << " ";
	
	for (int i = 0; i < graph[v].size(); i++) {
		int search = graph[v][i];
		if (!visit[search]) {
			DFS(search);
		}
	}
}
