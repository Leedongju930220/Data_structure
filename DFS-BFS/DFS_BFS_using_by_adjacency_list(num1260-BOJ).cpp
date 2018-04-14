#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
                                                            //인접리스트를 사용한 dfs, bfs
vector<int> a[1001];                                        //a벡터 1001개 생성
bool check[1001];                                           //bool 타입 사이즈1001인 check배열 생성
void dfs(int node){				            //매개변수로 node를 받는 dfs
	check[node] = true;				    //check의 node에 ture저장
	printf("%d ", node);				    //node 출력
	for (int i = 0; i < a[node].size(); i++){	    //i는 0부터 벡터a의 노드의 size만큼반복
		int next = a[node][i];			    //next에 벡터a의 node의 i를 저장
		if (check[node] == false){		    //만약 체크배열의node가 false,  즉 , 방문하지 않았다면
			dfs(next);			    //dfs(next)출력
		}													//
	}														//
}															//
															//
void bfs(int start){					    //매개변수로 start를 받는 bsf
	queue<int> q;					    //큐q 생성
	memset(check, false, sizeof(check));		    //check를 false로 check사이즈만큼 메모리셋
	check[start] = true;				    //체크배열의 start번째에 true저장
	q.push(start);					    //q에 start 푸시
	while (!q.empty()){				    //만약 q가 비지 않았다면 while계속 실행
		int node = q.front();			    //node에 q의 맨처음을 저장
		q.pop();				    //q의 맨처음 삭제
		printf("%d ", node);			    //node 출력
		for (int i = 0; i < a[node].size(); i++){   //i는 0부터 벡터a의 node번째의 사이즈만큼 for문
			int next = a[node][i];		    //next에  벡터a의 node번째의 i번째 값 저장
			if (check[next] == false){	    //만약 체크배열의 next번째가 false, 즉, 방문하지 않았다면
				check[next] = true;	    //check의 next번째에 true저장
				q.push(next);		    //q에 next 푸시
			}												//
		}													//
	}														//
}															//
int main(){													//
	int n, m, start;										//
	scanf("%d %d %d", &n, &m, &start);						//
	for (int i = 0; i < m; i++){							//
		int u, v;											//
		scanf("%d %d", &u, &v);								//
		a[u].push_back(v);									//
		a[v].push_back(u);									//
	}														//
	for (int i = 1; i <= n; i++){							//
		sort(a[i].begin(), a[i].end());						//
	}														//
	dfs(start);												//
	puts("");												//
	bfs(start);												//
	puts("");												//
															//
															//
	return 0;												//
}															//
