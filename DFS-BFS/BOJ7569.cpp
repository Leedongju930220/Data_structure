#include <cstdio>
#include <queue>
using namespace std;
// 1 = 익은토마토,  0 = 익지 않은 토마토 , -1 = 없는칸 
// 저장부터 모두 익음 = 0출력, 토마토가 모두 못익는 상황 = 1, 둘다 아니면 며칠걸리나 출력
#define Flag	10000000

struct axis {
	int x, y, z;
};

int width, height, length;
int map[100][100][100];
queue<axis> que;
int cnt;

axis make_Point(int z, int y, int x) {
	axis p;
	p.z = z;
	p.y = y;
	p.x = x;
	return p;
}

int bfs()
{
	axis p;
	int dz[6] = { -1, 1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, -1, 1, 0, 0 };
	int dx[6] = { 0, -0, 0, 0, -1, 1 };

	while (!que.empty()) {
		p = que.front();
		que.pop();

		for (int i = 0; i < 6; i++) {
			axis next = make_Point(p.z + dz[i], p.y + dy[i], p.x + dx[i]);

			if (next.z >= 0 && next.z < length && next.y >= 0
				&& next.y < height && next.x >= 0 && next.x < width) {
				if (map[next.z][next.y][next.x] == 0) {
					map[next.z][next.y][next.x] = map[p.z][p.y][p.x] + 1;
					que.push(next);
					cnt--;
				}
			}
		}
	}

	if (cnt <= 0)        
		return map[p.z][p.y][p.x] - Flag - 1;
	return -1;
}

int main()
{
	scanf("%d %d %d", &width, &height, &length);

	for (int z = 0; z < length; z++) {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				scanf("%d", &map[z][y][x]);

				if (map[z][y][x] == 1) {
					que.push(make_Point(z, y, x));
					map[z][y][x] += Flag;
				}
				else if (map[z][y][x] == 0)    cnt++;
			}
		}
	}

	printf("%d\n", bfs());

	return 0;
}
