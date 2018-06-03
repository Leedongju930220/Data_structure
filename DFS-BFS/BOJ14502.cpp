#include <cstdio>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

#define MAX 8

int pre_map[MAX][MAX] = { 0 };
int aft_map[MAX][MAX] = { 0 };
int row, colum;
int global_max = -1;

int xx[4] = { 1, 0, -1, 0 };
int yy[4] = { 0, -1, 0, 1 };

void zero_count(){
	int local_count = 0;
	for (int i = 0; i < colum; i++){
		for (int j = 0; j < row; j++){
			if ( aft_map[i][j] == 0) local_count++;
		}
	}
	if (global_max < local_count) global_max = local_count;
}
void copy_map(){
	for (int i = 0; i < colum; i++){
		for (int j = 0; j < row; j++){
			aft_map[i][j] = pre_map[i][j];
		}
	}
}
void bfs(int l_colum, int l_row){

	for (int i = 0; i < 4; i++){
		int next_x = l_row + xx[i];
		int next_y = l_colum + yy[i];
		if (aft_map[next_y][next_x] == 0 && next_x >= 0 && next_x <row && next_y >= 0 && next_y <colum){
			aft_map[next_y][next_x] = 2;
			bfs(next_y, next_x);
		}
	}

}
int main(){
	scanf("%d %d", &colum, &row);

	vector<pair<int,int>> v;
	
	int value = 0;
	for (int i = 0; i < colum; i++){
		for (int j = 0; j < row; j++){
			scanf("%1d", &value);
			pre_map[i][j] = value;
			if (value == 0) v.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < v.size()-2; i++){
		for (int j = i + 1; j < v.size()-1; j++){
			for (int k = j + 1; k < v.size(); k++){
				copy_map();
				aft_map[v[i].first][v[i].second] = 1;
				aft_map[v[j].first][v[j].second] = 1;
				aft_map[v[k].first][v[k].second] = 1;
				for (int map_colum = 0; map_colum < colum; map_colum++){
					for (int map_row = 0; map_row < row; map_row++){
						if (aft_map[map_colum][map_row] == 2){
							bfs(map_colum, map_row);
						}
					}
				}
				zero_count();
			}
		}
	}

	printf("%d", global_max);

	return 0;
}
