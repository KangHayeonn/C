#include <stdio.h>
#include <stdlib.h>

void DFS(int** arr, int N, int START) {
	int* dfs_arr = (int*)calloc(N ,sizeof(int));
	printf("%d ", START);
	dfs_arr[START] = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i][0] == START && dfs_arr[i] == 0)
			DFS(arr, N, i);
	}

	return;
}

void BFS(int*** arr, int N, int START) {

}

int main() {
	int N, M, V;
	int** arr;

	scanf("%d %d %d", &N, &M, &V);

	arr = (int**)malloc(sizeof(int*) * M);

	for (int i = 0; i < M; i++) arr[i] = (int*)malloc(sizeof(int) * 2);

	for (int i = 0; i < M; i++) 
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	printf("%d", arr[0][0]);

	for (int i = 0; i < M; i++)
		for (int j = 0; j < 2; j++)
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);

	DFS(arr, N, V);
	BFS(&arr, N, V);

	for (int i = 0; i < M; i++) free(arr[i]);

	free(arr);

	return 0;
}