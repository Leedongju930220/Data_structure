#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;									  // 비재귀로 구현한 dfs, bfs
vector<int> a[1001];									  // a벡터 1001개 만듬 마치 2차원배열이라고 생각하면 된다, a(1001)은 a의 초기크기를 1001로 만든거
bool check[1001];										  // bool타입 check배열 ,크리 1001
														  //
void dfs(int node){										  // node를 맞는 dfs함수
	stack<pair<int, int>> s;							  // pair<int, int>를 받는 stack s선언
	s.push(make_pair(node, 0));							  // s에 (node, 0)pair를 푸시한다
	check[node] = true;									  // check배열의 node에 true저장
	printf("%d ", node);								  // node 출력
	while (!s.empty()){									  // s가 비지 않았다면 while
		int node = s.top().first;						  // node에 s.top의 first 인자를 저장
		int start = s.top().second;						  // start에 s.top의 second 인자를 저장
		s.pop();										  // s.pop()
		for (int i = start; i < a[node].size(); i++){	  // i는 start부터 a[node].size만큼 반복
			int next = a[node][i];						  // next에 a[node][i]를 저장 , 벡터a의 node번째의 i인자
			if (check[next] == false){					  // check의 next가 false이면 ,즉 next를 방문하지 않았다면
				printf("%d ", next);					  // next출력
				check[next] = true;						  // check의 next에 true저장
				s.push(make_pair(node, i + 1));			  // (node , i+1) pair를 s에 푸시
				s.push(make_pair(next, 0));				  // 
				break;									  //
			}											  //
		}												  //
	}													  //
}														  //
														  //
void bfs(int start){									  // start를 매개변수로 받는 bfs함수
	queue<int> q;										  // 큐 q 선언
	memset(check, false, sizeof(check));				  // check함수를 size만쿰 false로 메모리 셋
	check[start] = true;								  // 체크함수의 start를  true
	q.push(start);										  // start를 q에 푸시
	while (!q.empty()){									  // q가 비지않았다면 while
		int node = q.front();							  // node에 q.front()
		q.pop();										  // q.pop
		printf("%d ", node);							  // node 출력
		for (int i = 0; i < a[node].size(); i++){		  // i는 0부터 a벡터의 node번째의 size만큼 for문
			int next = a[node][i];						  // next에 벡터 a의 node번째의 i번째 저장
			if (check[next] == false){					  // 만약 check의 next가 false면
				check[next] = true;						  // check의 next에 true 저장
				q.push(next);							  // next를 q에 푸시
			}											  //
		}												  //
	}													  //
}														  //
int main(){												  //
	int n, m, start;									  //
	scanf("%d %d %d ", &n, &m, &start);					  //
	for (int i = 0; i < m; i++){						  // i는 0부터 m-1까지 for문
		int u, v;										  // 
		scanf("%d %d", &u, &v);							  //
		a[u].push_back(v);								  // 벡터a의 [u]에 v 푸시
		a[v].push_back(u);
	}						                              // 벡터a의 [v]에 u푸시
	for (int i = 1; i <= n; i++){						  // i는 1부터 n까지 for문
		sort(a[i].begin(), a[i].end());					  // a[i]를 sort한다
	}													  //
														  //
	dfs(start);											  //
	puts("");											  //
	bfs(start);											  //
	puts("");											  //

	return 0;
}
