#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

#define MAX 101


int map_one[MAX][MAX] = { 0 };
int map_two[MAX][MAX] = { 0 };
int check[MAX][MAX] = { 0 };
int area_one = 0;
int area_two = 0;
int xx[4] = { 1, 0, -1, 0 };
int yy[4] = { 0, -1, 0, 1 };
char cur;

void bfs(int row, int colum){
	check[row][colum] = true;
	
	for (int i = 0; i < 4; i++){
		int next_x = row + xx[i];
		int next_y = colum + yy[i];
		if (check[next_x][next_y] == false && map_one[row][colum] == map_one[next_x][next_y]){
			bfs(next_x, next_y);
		}
	}
}
void bfs1(int row, int colum){
	check[row][colum] = true;

	for (int i = 0; i < 4; i++){
		int next_x = row + xx[i];
		int next_y = colum + yy[i];
		if (check[next_x][next_y] == false && map_two[row][colum] == map_two[next_x][next_y]){
			bfs1(next_x, next_y);
		}
	}
}

int main(){
	int colum, row;
	char color;
	scanf("%d", &colum);
	row = colum;
	for (int i = 0; i < colum; i++){
		for ( int j = 0; j < row; j++){
			scanf(" %c", &color);
			if (color == 'R'){
				map_one[i][j] = 2;
				map_two[i][j] = 2;
			}
			else if (color == 'G'){
				map_one[i][j] = 2;
				map_two[i][j] = 3;
			}
			else { map_one[i][j] = 3; map_two[i][j] = 4; }
		}
	}

	for (int i = 0; i < colum; i++){
		for (int j = 0; j < row; j++){
			if (check[i][j] == false)
				area_one++;
				bfs( i, j);
		}
	}
	for (int i = 0; i<row; i++){
		memset(check[i], false, sizeof(int)* colum);
	}
	for (int i = 0; i < colum; i++){
		for (int j = 0; j < row; j++){
			if (check[i][j] == false)
				area_two++;
			bfs1(i, j);
		}
	}

	printf("%d %d", area_two, area_one);

	return 0;
}
