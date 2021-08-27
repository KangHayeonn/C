#include <stdio.h>
#include <stdlib.h>

void DFS(int** graph, int N, int START, int** dfs_arr) {
	printf("%d ", START);
	dfs_arr[0][START] = 1;
	
	for (int i = 1; i < N + 1; i++) {
		if (graph[START][i] == 1 && dfs_arr[0][i] == 0) {
			DFS(graph, N, i, dfs_arr);  // dfs_arr 주솟값 자체를 보냄
		}
	}
	return;
}

void BFS(int*** arr, int N, int START, int** bfs_arr) {

}

int main() {
	int N, M, V;
	int** graph;
	int j, k;

	scanf("%d %d %d", &N, &M, &V);

	int* dfs_arr = (int*)calloc(N + 1, sizeof(int));
	int* bfs_arr = (int*)calloc(N + 1, sizeof(int));

	graph = (int**)malloc(sizeof(int*)*(N+1));

	for (int i = 0; i < N+1; i++) graph[i] = (int*)calloc(N+1, sizeof(int));

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &j, &k);
		graph[j][k] = 1;
		graph[k][j] = 1;
	}
	/*
	for (int i = 0; i < N+1; i++)
		for (int j = 0; j < N+1; j++)
			printf("graph[%d][%d] = %d\n", i, j, graph[i][j]);
	*/
	DFS(graph, N, V , &dfs_arr); // 이차원 배열처럼 dfs_arr 주솟값 자체를 보냄
	BFS(&graph, N, V, &bfs_arr);

	for (int i = 0; i < M; i++) free(graph[i]);

	free(graph);
	free(dfs_arr);
	free(bfs_arr);

	return 0;
}