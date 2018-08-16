#include<cstdio>
#define MAX 6
// N combination N/2
int num[MAX];
int N = MAX;
// 8 conbination 4
void combi(int p, int d){
	if (d == MAX/2){
		for (int i = 1; i <= MAX; i++){
			if (num[i] == 1)printf("%d", i);
		}
		printf("\n");
		for (int i = 1; i <= MAX; i++){
			if (num[i] == 0) printf("%d", i);
		}
		printf("\n\n\n\n");
		return;
	}
	if (p == MAX+1) return;
	num[p] = 1;
	combi(p + 1, d + 1);
	num[p] = 0;
	combi(p + 1, d);

}
int main(){
	combi(1, 0);
	return 0;
}
