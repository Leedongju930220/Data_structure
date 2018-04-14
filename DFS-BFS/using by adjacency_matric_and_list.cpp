#include <cstdio>
#include <vector>


using namespace std;
/*

인접행렬 : nxm차원 배열을 이용

1 : 가중치가 없는 양방향 그래프  nxm차원 배열
int a[10][10];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u][v] = a[v][u] = 1;  //양방향이 아닌 단방향이면 a[u][v]나 a[v][u]중 하나만 저장
	}
	return 0;
}



2 : 가중치가 있는 양방향 그래프 nxm차원 배열

int a[10][10];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		int u,v,w;
		scanf("%d %d %d", &u, &v, &w);
		a[u][v] = a[v][u] = w;
	}

	return 0;
}




인접리스트 : 링크드 리스크를 이용해서 구현
하지만 링크드리스크는 구현시간이 오래걸려서 vector와 같이 동적할당 배열을 이용

A[1] : 2 ,5 
A[2] : 1 ,3 ,4 ,5
A[3] : 2 ,4
A[4] : 3 ,5 ,2 ,6
A[5] : 1 ,2 ,4
A[6] : 4


vector<int> a[10];  a(10) > size가10인 벡터 a, a[10] a라는 벡터를 10개 생성
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	return 0;
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> a(n + 1);
	for (int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}


	return 0;
}

//인접리스트를 vector<pair<int, int>>를 이용해 first에는 연결된 노드번호, second에는 가중치를 저장할 수 있음, 시간복잡도가 작음
vector<pair<int, int>> a[10];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back(make_pair(v, w));
		a[v].push_back(make_pair(u, w));
	}

	return 0;
}

//최종 공간복잡도 : 인접행렬 빅오(v**2), 인접리스트 빅오(E) ((v:노드갯수, E:간선갯수))

//그래프의 탐색
//DFS => 스택을 사용, 스택을 이용해서 갈 수 있는 만큼 최대한 간다, 갈 수 없으면 이전 정점으로 돌아온다
//BFS => 큐를 사용 , 큐를 이용해서 지금 위치에서 갈 수 있는 것을 모두 큐에 넣는 방식, 큐에 넣을 때 방문했다고 체크해야 한다.



void dfs1(int x){                               //인접행렬을 이용한 dfs구현, 공간복잡도높음
	check[x] = true;                              //현재 노드의 체크배열에 방문했다고 true넣음
	printf("%d", x);                              //현재 방문한 노드 출력
	for (int i = 1; i <= n; i++){                 //1번부터 마지막노드까지 for문
		if (a[x][i] == 1 && check[i] == false){   //만약 현재노드와 i노드가 연결되어 있고 방문을 안했으면 dfs1(i)호출
			dfs1(i);
		}
	}
}

void dfs2(int x){                                  //인접리스트를 이용한 dfs구현 , 위의 인접행렬보다 공간복잡도 낮음
	check[x] = true;                               //현재 노드의 체크배열에 방문했다고 ture넣음
	printf("%d", x);                               //현재노드 출력
	for (int i = 0; i < a[x].size(); i++){         //i는 0부터 a벡터의 사이즈만큼 for문
		int y = a[x][i];                           //백터a의 x번째의 i 값을 y에 넣는다
		if (check[y] == false){                    //만약 y를 방문하지 않았으면
			dfs2(y);                               // dfs2(y)호출
		}                 
	}
}

bfs1 : while이용,인접행렬이용

queue<int> q;                                    //q 큐 생성
check[1] = true;                                 //체크배열의 1번에 true
q.push(1);                                       // 시작
while (!q.empty()){                              // q가 빌 때까지 실행
	int x = q.front();                           //x에 큐에서 하나 꺼내서 저장
	q.pop();                                     //x앞에 삭제
	printf("%d", x);                             //x출력
	for (int i = 1; i <= n; i++){                //1부터 n(끝)까지 for문
		if (a[x][i] == 1 && check[i] == false){  //x와 i노드가 연결되어 있고 i노드를 아직 방문안했다면
			cehck[i] = true;                     //체크배열i번째 true
			q.push(i);                           //q에 i 푸시후 다시 while문
		}
	}
}

bfs2 : 리스트 이용

queue<int> q;
check[1] = true;
q.push(1);
while (!q.empty()){ 
	int x = q.front();     
	q.pop();
	printf("%d", x);
	for (int i = 0; i < a[x].size(); i++){       //벡터 a의x번째의 사이즈만큼 반복
		int y = a[x][i];                         //y에  벡터a의x번째의 i번째 값 저장
		if (check[y] == false){                  //만약 y를 방문하지 않았다면
			check[y] = true;                     //y에 true
			q.push(y);                           //q에 y를 푸시후 다시 while문
		}
	}
}*/


