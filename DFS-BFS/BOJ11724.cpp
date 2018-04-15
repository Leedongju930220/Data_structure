//dfs,bfs 두방식으로 풀어보았다.

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

vector<int> edge[1001];
queue<int> q;
bool check[1001];
int connection_count = 0;

void dfs(int node){
	check[node] = true;
	for (int i = 0; i < edge[node].size(); i++){
		int next = edge[node][i];
		if (check[next] == false){
			dfs(next);
		}
	}
}
void bfs(int node){
	q.push(node);
	while (!q.empty()){
		int start = q.front();
		q.pop();
		for (int i = 0; i < edge[start].size(); i++){
			int next = edge[start][i];
			if (check[next] == false){
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(){
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	while (m--){
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 0; i < n; i++){
		sort(edge[i].begin(), edge[i].end());
	}
	memset(check, false, sizeof(check));
	for (int i = 1; i <= n; i++){
		if (check[i] == false){
			connection_count++;
			//dfs(i);
			bfs(i);
		}
	}
	printf("%d", connection_count);

	return 0;
}
