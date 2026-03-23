/*
 * main.c - Implementação completa do TAD Grafo (tudo em um arquivo)
 *
 * Estrutura: Matriz de adjacência com pesos
 * Arestas inexistentes são representadas por -1
 *
 * Grafo da imagem:
 * Vértices: 1..8
 * Arestas (u, v, peso):
 *   1-3: 4,  1-2: 1,  1-8: 3
 *   2-3: 5,  2-8: 2,  2-4: 6
 *   3-4: 9,  3-5: 8
 *   4-5: 7,  4-6: 10, 4-7: 11
 */

#include <stdio.h>
#include <stdlib.h>

/* =====================================================================
 *  DECLARAÇÕES (equivalente a graph.h)
 * ===================================================================== */

typedef struct {
    int  n_vertices;   /* número de vértices (1-indexado) */
    int **adj;         /* matriz de adjacência n x n      */
} Graph;

/* Constrói um grafo com N vértices; todas as arestas iniciam em -1 */
Graph *MyGraph(int N);

/* Adiciona (ou sobrescreve) aresta u->v com peso w (grafo não-dirigido) */
void add_edge(Graph *G, int u, int v, int w);

/* Retorna 1 se existe aresta u->v, 0 caso contrário */
int exist_edge(Graph *G, int u, int v);

/* Imprime os vizinhos de um vértice */
void neighbors(Graph *G, int v);

/* Remove a aresta u->v; imprime -1 se não existir */
void remove_edge(Graph *G, int u, int v);

/* Imprime vértices e arestas do grafo */
void print_info(Graph *G);

/* Libera a memória do grafo */
void delete_graph(Graph **G);

/* Retorna o vértice com maior número de vizinhos (primeiro, se empate) */
int max_neighbors(Graph *G);

/* Imprime a matriz de adjacência e retorna o ponteiro para ela */
int **adjacency_matrix(Graph *G);

/* =====================================================================
 *  IMPLEMENTAÇÃO (equivalente a graph.c)
 * ===================================================================== */

Graph *MyGraph(int N) {
    Graph *G = (Graph *)malloc(sizeof(Graph));
    if (!G) { fprintf(stderr, "Erro: sem memória.\n"); exit(1); }

    G->n_vertices = N;

    /* Aloca matriz N x N */
    G->adj = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        G->adj[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            G->adj[i][j] = -1;   /* -1 = sem aresta */
    }
    return G;
}

/* Conversão 1-indexado -> 0-indexado internamente */
void add_edge(Graph *G, int u, int v, int w) {
    G->adj[u-1][v-1] = w;
    G->adj[v-1][u-1] = w;   /* grafo não-dirigido */
}

int exist_edge(Graph *G, int u, int v) {
    return (G->adj[u-1][v-1] != -1) ? 1 : 0;
}

void neighbors(Graph *G, int v) {
    printf("Vizinhos de %d: ", v);
    int found = 0;
    for (int j = 0; j < G->n_vertices; j++) {
        if (G->adj[v-1][j] != -1) {
            printf("%d (peso=%d) ", j+1, G->adj[v-1][j]);
            found = 1;
        }
    }
    if (!found) printf("nenhum");
    printf("\n");
}

void remove_edge(Graph *G, int u, int v) {
    if (G->adj[u-1][v-1] == -1) {
        printf("-1\n");
        return;
    }
    G->adj[u-1][v-1] = -1;
    G->adj[v-1][u-1] = -1;
}

void print_info(Graph *G) {
    printf("=== Informações do Grafo ===\n");
    printf("Vértices: %d\n", G->n_vertices);
    printf("Arestas:\n");
    for (int i = 0; i < G->n_vertices; i++)
        for (int j = i+1; j < G->n_vertices; j++)
            if (G->adj[i][j] != -1)
                printf("  %d -- %d  (peso=%d)\n", i+1, j+1, G->adj[i][j]);
    printf("============================\n");
}

void delete_graph(Graph **G) {
    if (!*G) return;
    for (int i = 0; i < (*G)->n_vertices; i++)
        free((*G)->adj[i]);
    free((*G)->adj);
    free(*G);
    *G = NULL;
}

int max_neighbors(Graph *G) {
    int best_v   = 1;
    int best_cnt = 0;
    for (int i = 0; i < G->n_vertices; i++) {
        int cnt = 0;
        for (int j = 0; j < G->n_vertices; j++)
            if (G->adj[i][j] != -1) cnt++;
        if (cnt > best_cnt) {
            best_cnt = cnt;
            best_v   = i + 1;
        }
    }
    printf("Vértice com mais vizinhos: %d (%d vizinhos)\n", best_v, best_cnt);
    return best_v;
}

int **adjacency_matrix(Graph *G) {
    printf("Matriz de Adjacência (%d x %d):\n", G->n_vertices, G->n_vertices);
    printf("   ");
    for (int j = 0; j < G->n_vertices; j++) printf("%4d", j+1);
    printf("\n");
    for (int i = 0; i < G->n_vertices; i++) {
        printf("%2d:", i+1);
        for (int j = 0; j < G->n_vertices; j++)
            printf("%4d", G->adj[i][j]);
        printf("\n");
    }
    return G->adj;
}

/* =====================================================================
 *  MAIN (main.c)
 *  Segue o mesmo formato de switch/case da imagem fornecida.
 *  Cases adicionados para as operações a..i do enunciado.
 * ===================================================================== */

int main(void) {
    int option;
    int N, x, y, w;
    int res;
    int print_status = 1;

    Graph *G;

    scanf("%d", &option);

    while (option != -1) {
        switch (option) {

        /* --- case 0: criar grafo com N vértices --- */
        case 0:
            scanf("%d", &N);
            G = MyGraph(N);
            break;

        /* --- case 1: adicionar aresta --- */
        case 1:  /* adicionamos */
            scanf("%d %d %d", &x, &y, &w);
            add_edge(G, x, y, w);
            break;

        /* --- case 2: verificar se aresta existe --- */
        case 2:  /* exist_edge */
            scanf("%d %d", &x, &y);
            res = exist_edge(G, x, y);
            print_status = 0;
            break;

        /* --- case 3: vizinhos de um vértice --- */
        case 3:
            scanf("%d", &x);
            neighbors(G, x);
            break;

        /* --- case 4: remover aresta --- */
        case 4:
            scanf("%d %d", &x, &y);
            remove_edge(G, x, y);
            break;

        /* --- case 5: print_info --- */
        case 5:
            print_info(G);
            break;

        /* --- case 6: delete_graph --- */
        case 6:
            delete_graph(&G);
            printf("Grafo removido da memória.\n");
            break;

        /* --- case 7: max_neighbors --- */
        case 7:
            res = max_neighbors(G);
            print_status = 0;
            break;

        /* --- case 8: adjacency_matrix --- */
        case 8:
            adjacency_matrix(G);
            break;

        default:
            printf("unrecognized option %d!\n", option);
        }

        scanf("%d\n", &option);
    }

    /* Ao sair com -1: imprime info ou resultado da última query */
    if (option == -1) {
        if (print_status)
            print_info(G);
        else
            printf("%d\n", res);
    }

    delete_graph(&G);
    return 0;
}

/*
 * -----------------------------------------------------------------------
 *  EXEMPLO DE ENTRADA para reproduzir o grafo da imagem (8 vértices):
 *
 *  0 8        <- criar grafo com 8 vértices
 *  1 1 3 4    <- aresta 1-3 peso 4
 *  1 1 2 1    <- aresta 1-2 peso 1
 *  1 1 8 3    <- aresta 1-8 peso 3
 *  1 2 3 5    <- aresta 2-3 peso 5
 *  1 2 8 2    <- aresta 2-8 peso 2
 *  1 2 4 6    <- aresta 2-4 peso 6
 *  1 3 4 9    <- aresta 3-4 peso 9
 *  1 3 5 8    <- aresta 3-5 peso 8
 *  1 4 5 7    <- aresta 4-5 peso 7
 *  1 4 6 10   <- aresta 4-6 peso 10
 *  1 4 7 11   <- aresta 4-7 peso 11
 *  2 3 1      <- exist_edge(3,1)  -> res=1
 *  3 2        <- neighbors(2)
 *  4 1 2      <- remove_edge(1,2)
 *  7          <- max_neighbors
 *  8          <- adjacency_matrix
 *  -1         <- encerrar
 * -----------------------------------------------------------------------
 */
