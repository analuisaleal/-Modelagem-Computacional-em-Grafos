# 📊 TAD Grafo em C — Matriz de Adjacência

Implementação de um **Tipo Abstrato de Dados (TAD) para Grafos** em linguagem C, utilizando **matriz de adjacência com pesos**. O projeto foi desenvolvido como exercício acadêmico e organiza a solução nos moldes de um TAD completo (`graph.h` / `graph.c` / `main.c`), entregue em arquivo único para compatibilidade com juízes online.

---

## 📁 Estrutura do Projeto

```
grafos/
└── main.c      # Declarações (graph.h) + Implementação (graph.c) + Main
```

> A separação em seções comentadas dentro do `main.c` reflete a organização TAD:
> - **Seção 1** — Declarações de tipos e protótipos (equivalente a `graph.h`)
> - **Seção 2** — Implementação das funções (equivalente a `graph.c`)
> - **Seção 3** — Programa principal com menu `switch/case` (`main.c`)

---

## ⚙️ Compilação e Execução

**Pré-requisitos:** GCC instalado.

```bash
# Compilar
gcc -o grafo main.c

# Executar (entrada manual)
./grafo

# Executar com arquivo de entrada
./grafo < entrada.txt
```

---

## 🗂️ Operações Implementadas

| Case | Função | Descrição |
|------|--------|-----------|
| `0`  | `MyGraph(N)` | Cria grafo com N vértices; arestas iniciam em `-1` |
| `1`  | `add_edge(G, u, v, w)` | Adiciona ou sobrescreve aresta com peso |
| `2`  | `exist_edge(G, u, v)` | Retorna `1` se a aresta existe, `0` caso contrário |
| `3`  | `neighbors(G, v)` | Imprime os vizinhos e pesos de um vértice |
| `4`  | `remove_edge(G, u, v)` | Remove aresta; imprime `-1` se não existir |
| `5`  | `print_info(G)` | Exibe todos os vértices e arestas do grafo |
| `6`  | `delete_graph(&G)` | Libera toda a memória alocada |
| `7`  | `max_neighbors(G)` | Retorna o vértice com mais vizinhos (primeiro em empate) |
| `8`  | `adjacency_matrix(G)` | Imprime e retorna a matriz de adjacência |
| `-1` | — | Encerra o programa |

---

## 📐 Estrutura Interna

```c
typedef struct {
    int  n_vertices;   // número de vértices (indexado a partir de 1)
    int **adj;         // matriz de adjacência N x N
} Graph;
```

- Grafos **não-dirigidos**: ao inserir aresta `(u, v, w)`, ambas as posições `adj[u][v]` e `adj[v][u]` são preenchidas.
- Ausência de aresta representada por **`-1`**.
- Vértices usam **índice 1-based** na interface pública.

---

## 🧪 Exemplo de Entrada e Saída

O grafo abaixo é usado como exemplo de teste:

```
    3 ———8——— 5
   /|\        \
  4 5 9        7
 /  |  \        \
1—1—2—6—4—10——6
 \  |     \
  3 2      11
   \|       \
    8         7
```

**Entrada (`entrada.txt`):**

```
0 8
1 1 3 4
1 1 2 1
1 1 8 3
1 2 3 5
1 2 8 2
1 2 4 6
1 3 4 9
1 3 5 8
1 4 5 7
1 4 6 10
1 4 7 11
2 3 1
3 2
4 1 2
7
8
-1
```

**Saída esperada:**

```
1                          ← exist_edge(3,1)
Vizinhos de 2: 3 (peso=5) 8 (peso=2) 4 (peso=6)    ← neighbors(2)
                           ← remove_edge(1,2) — sem saída
Vértice com mais vizinhos: 4 (4 vizinhos)            ← max_neighbors
Matriz de Adjacência (8 x 8): ...                    ← adjacency_matrix
=== Informações do Grafo ===                         ← print_info (saída final)
```

---

## 📚 Conceitos Abordados

- Alocação dinâmica de memória (`malloc` / `free`)
- Ponteiros e ponteiros para ponteiros
- Matrizes dinâmicas bidimensionais
- TAD (Tipo Abstrato de Dados)
- Grafos não-dirigidos ponderados
- Representação por matriz de adjacência

---

## 👤 Autores

Ana Luísa Pereira da Silva Leal
Mariane Ferreira dos Santos
Pedro Henrique.....
