#include <cstdio>
#include <cstring>										   //
#include <queue>										   // 간선리스트사용한 bfs, dfs
#include <algorithm>									   // 간선리스트란 ?
														   // 배열을 이용해서 구현하고, 모든 간선의 from,to를 저장
using namespace std;									   // 만약 4번노드와 6번노드가 가중치 3으로 연결되어있으면
                                                           // edge[4][6] = 3; 그후 cnt[edge[4][6]]
struct Edge{											   // 엣지 구조체 ,from과 to를 변수로 가짐
	int from, to;										   //
};														   //
														   //
Edge edge[20001];										   // 크기가 20001인 엣지 구조체 선언( 즉 20001개) 
int cnt[1001];											   // int형 cnt배열 생성
bool check[1001];										   // bool형 크기가 1001인  check배열 선언
bool cmp(const Edge &u, const Edge &v){					   // 반환형이 bool이고 참조자 엣지u, 엣지 v를 const로 받는 cnt함수
	if (u.from == v.from){								   // u.from과 v.from이 같다면
		return u.to < v.to;								   // u.to < v.to 반환
	}													   //
	else{												   // u.from과 v.from이 같지않다면
		return u.from > v.from;							   // u.from > v.from 반환
	}													   //
}														   //
														   //
void dfs(int node){										   // node를 매개변수로 받는 dfs함수
	check[node] = true;									   // check배열의 node에 true 저장
	printf("%d ", node);								   // node 출력
	for (int i = cnt[node - 1]; i < cnt[node]; i++){	   // i는 cnt[node-1]부터 cnt[node]까지
		int next = edge[i].to;							   // next에 edge[i].to 저장
		if (check[next] == false){						   // 만약 check의 next번째가 false라면
			dfs(next);									   // dfs(next)호출
		}												   //
	}													   //
}														   //
														   //
void bfs(int start){									   // start를 매개변수로 받는 bfs
	queue<int> q;										   // 큐 q선언
	q.push(start);										   // q에 start 푸시
	check[start] = true;								   // check배열의 start번째에 true
	while (!q.empty()){									   // 만약 q가 비지 않았으면
		int node = q.front();							   // node에 q.front저장
		q.pop();										   // q.pop
		printf("%d ", node);							   // node 출력
		for (int i = cnt[node - 1]; i < cnt[node]; i++){   // i는 cnt[node-1] 부터 cnt[node]까지 
			int next = edge[i].to;						   // next에 edge[i].to 저장
			if (check[next] == false){					   // check배열이 next번째가 false이면
				check[next] = true;						   // true 저장
				q.push(next);							   // q에 next 푸시
			}											   //
		}												   //
	}													   //
}														   //
														   //
int main(){												   //
	int n, m, start;									   // 
	scanf("%d %d %d", &n, &m, &start);					   //
	for (int i = 0; i < m; i++){						   //  i는 0부터 m까지
		scanf("%d %d", &edge[i].from, &edge[i].to);		   //  i의 edge.from ,to를 입력
		edge[i + m].from = edge[i].to;					   //  양방향으로 연결되어 있으니깐
		edge[i + m].to = edge[i].from;					   //  edge[i+m].from,to에 to,from 저장
	}													   //
	m *= 2;												   //  2개로 늘림
	sort(edge, edge + m, cmp);							   //  edge를 sort한다.
	for (int i = 0; i < m; i++){						   //  i는 0부터 m까지
		cnt[edge[i].from] += 1;							   //  cnt[edge[i].from] +=1
	}													   //
	for (int i = 1; i < n; i++){						   //  i는 1부터 n-1까지
		cnt[i] += cnt[i - 1];							   //  cnt[i] = cnt[i] +cnt[i+1]
	}													   //
	dfs(start);											   //
	printf("\n");										   //
	memset(check, false, sizeof(check));				   //
	bfs(start);											   //
	printf("\n");										   //

	return 0;
}
