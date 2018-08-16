#include<cstdio>

int num[9];
int N = 8;

void combi(int p, int d){
	if (d == 4){
		for (int i = 1; i <= 8; i++){
			if (num[i] == 1)printf("%d", i);
		}
		printf("\n");
		return;
	}
	if (p == 9) return;
	num[p] = 1;
	combi(p + 1, d + 1);
	num[p] = 0;
	combi(p + 1, d);

}
int main(){
	combi(1, 0);
	return 0;
}
