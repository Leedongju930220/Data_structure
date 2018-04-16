#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edge[20001];
int color[20001];

void dfs(int start, int c){
	color[start] = c;
	for (int i = 0; i < edge[start].size(); i++){
		int next = edge[start][i];
		if (color[next] == 0){
			dfs(next, 3 - c);
		}
	}
}

int main(){
	int k, n, e;
	scanf("%d", &k);
	while (k--){
		scanf("%d %d", &n, &e);
		for (int i = 1; i <= n; i++){
			edge[i].clear();
			color[i] = 0;
		}
		for (int i = 1; i <= e; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for (int i = 1; i <= n; i++){
			if (color[i] == 0){
				dfs(i, 1);
			}
		}
		bool answer = true;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < edge[i].size(); j++){
				if (color[i] == color[edge[i][j]]){
					answer = false;
				}
			}
		}
		printf("%s\n", (answer) ? "YES" : "NO");
	}


	return 0;
}

