#include <stdio.h>

#define MAX 100
#define INF 9999999

int D[MAX][MAX]; // Distancias
int R[MAX][MAX]; // Recorridos
int n;           // Numero de nodos

void mostrarMatriz(int M[MAX][MAX], char *nombre) {
    printf("\n--- %s ---\n", nombre);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (M[i][j] == INF) printf("%7s", "INF");
            else printf("%7d", M[i][j]);
        }
        printf("\n");
    }
}

void imprimirCamino(int i, int j) {
    if (i == j) {
        printf("%d", i);
        return;
    }
    printf("%d -> ", i);
    imprimirCamino(R[i][j], j);
}

int main() {
    // 1. Lectura
    printf("Numero de nodos: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("\nIngresa la matriz (-1 = Infinito):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int peso;
            scanf("%d", &peso);
            if (peso == -1) {
                D[i][j] = INF;
                R[i][j] = 0;
            } else {
                D[i][j] = peso;
                if (i != j) R[i][j] = j;
                else R[i][j] = 0;
            }
            if (i == j) D[i][j] = 0;
        }
    }

    printf("\n\n[Estado Inicial]");
    mostrarMatriz(D, "Matriz Inicial");

    // 2. Algoritmo
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (D[i][k] != INF && D[k][j] != INF) {
                    if (D[i][k] + D[k][j] < D[i][j]) {
                        D[i][j] = D[i][k] + D[k][j];
                        R[i][j] = R[i][k];
                    }
                }
            }
        }
    }

    // 3. Resultados
    printf("\n[Resultados Finales]");
    mostrarMatriz(D, "Matriz D (Distancias)");
    mostrarMatriz(R, "Matriz R (Recorridos)");

    // 4. Consultas
    printf("\n\n=== Consultar Rutas ===\n");
    printf("Ingresa pares 'Origen Destino' (o '0 0' para salir):\n");
    
    int o, d;
    // El ciclo lee mientras haya datos. Si pegas todo de golpe, los leera uno por uno.
    while (scanf("%d %d", &o, &d) == 2) {
        if (o == 0 && d == 0) break; // Salida manual

        if (o < 1 || o > n || d < 1 || d > n) {
            printf("\nError: Nodos invalidos (%d %d)\n", o, d);
            continue;
        }

        printf("Ruta %d a %d: ", o, d);
        if (D[o][d] == INF) {
            printf("No hay camino.\n");
        } else {
            imprimirCamino(o, d);
            printf(" (Costo: %d)\n", D[o][d]);
        }
    }
    printf("Fin del programa.\n");

    return 0;
}