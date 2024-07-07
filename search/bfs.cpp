#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[N];
bool visit[N];

void DFS(int start) {
	queue<int> q;
	q.push(start);
	visit[0] = true;
	
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		
		for (int i = 0; i < graph[front].size(); i++) {
			int search = graph[front][i];
			if (!visit[search]) {
				visit[search] = 1;
				q.push(search);
			}
		}
	}
}
