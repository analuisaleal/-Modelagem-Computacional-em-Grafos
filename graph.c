#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct
{
  int **matrix;
  int n; // número de vertices
} Graph;

// a) Cria um grafo com N vértices; todas as arestas iniciam em -1
Graph *MyGraph(int n)
{
  Graph *G = (Graph *)malloc(sizeof(Graph));

  if (G == NULL)
  {
    fprintf(stderr, "Erro: sem memória.\n");
    exit(1);
  }

  G->n = n;
  G->matrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    G->matrix[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++)
    {
      G->matrix[i][j] = -1;
    }
  }
}

// b) Adiciona (ou sobrescreve) aresta entre u e v com peso w
void add_edge(Graph *G, int u, int v, int w)
{
  G->matrix[u - 1][v - 1] = w;
  G->matrix[v - 1][u - 1] = w;
}

// c) Verifica se aresta (u,v) existe: retorna 1 se sim, 0 se não
int exist_edge(Graph *G, int u, int v)
{
  return (G->matrix[u - 1][v - 1] != -1) ? 1 : 0;
}

// d) Imprime os vizinhos do vértice v
void neighbors(Graph *G, int v)
{
  int found = 0;

  for (int i = 0; i < G->n; i++)
  {
    if (G->matrix[v - 1][i] != -1)
    {
      printf("%d, ", i + 1);
      found = 1;
    }
  }

  if (!found)
    printf("-1");

  printf("\n");
}

// e) Remove aresta (u,v); imprime -1 se não existir
void remove_edge(Graph *G, int u, int v)
{
  if (G->matrix[u - 1][v - 1] == -1)
  {
    printf("-1\n");
    return;
  }

  G->matrix[u - 1][v - 1] = -1;
  G->matrix[v - 1][u - 1] = -1;
}

void print_info(Graph *G)
{
}

void delete_graph(Graph *G)
{
}

int max_neighbors(Graph *G)
{
}

void adjacency_matrix(Graph *G)
{
}
