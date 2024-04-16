#include <stdio.h>

int main() {
  int sudoku[9][9], op, linha = 0, coluna = 0, numero, contagem = 0,
                        repeticao = 0, quadrante;

  for (int l = 0; l < 9; l++) {
    for (int c = 0; c < 9; c++) {
      scanf("%d%*c", &sudoku[l][c]);
    }
  }

  do {
    scanf("%d%*c", &op);
    switch (op) {
    case 0:

      break;
    case 1:
      scanf("%d%*c", &linha);
      scanf("%d%*c", &coluna);
      scanf("%d%*c", &numero);
      sudoku[linha][coluna] = numero;
      break;

    case 2:
      linha = 0;
      repeticao = 0;
      coluna = 0;
      scanf("%d%*c", &linha);
      for (int l = 0; l < 9; l++) {
        contagem = 0;
        for (int c = 0; c < 9; c++) {
          if (sudoku[linha][coluna] == sudoku[linha][c]) {
            contagem++;
          }
          if (contagem > 1) {
            repeticao++;
          }
        }
        coluna++;
      }
      if (repeticao > 1) {
        printf("S\n");
      } else {
        printf("N\n");
      }
      break;

    case 3:
      linha = 0;
      repeticao = 0;
      coluna = 0;
      scanf("%d%*c", &coluna);
      for (int c = 0; c < 9; c++) {
        contagem = 0;
        for (int l = 0; l < 9; l++) {
          if (sudoku[linha][coluna] == sudoku[l][coluna]) {
            contagem++;
          }
          if (contagem > 1) {
            repeticao++;
          }
        }
        linha++;
      }
      if (repeticao > 0) {
        printf("S\n");
      } else {
        printf("N\n");
      }
      break;

    case 4:
      scanf("%d%*c", &quadrante);
      repeticao = 0;
      linha = 0;
      coluna = 0;
      if (quadrante < 3) {
        linha = 0;
      } else if (quadrante >= 3 && quadrante <= 5) {
        linha = 3;
      } else if (quadrante >= 6 && quadrante <= 8) {
        linha = 6;
      }
      if (quadrante == 0 || quadrante == 3 || quadrante == 6) {
        coluna = 0;
      } else if (quadrante == 1 || quadrante == 4 || quadrante == 7) {
        coluna = 3;
      } else if (quadrante == 2 || quadrante == 5 || quadrante == 8) {
        coluna = 6;
      }
      for (int l = linha; l < linha + 3; l++) {
        for (int c = coluna; c < coluna + 3; c++) {
          contagem = 0;
          for (int ll = linha; ll < linha + 3; ll++) {
            for (int cc = coluna; cc < coluna + 3; cc++) {
              if (sudoku[l][c] == sudoku[ll][cc] && (l != ll || c != cc)) {
                contagem++;
              }
            }
          }
          if (contagem > 0) {
            repeticao++;
          }
        }
      }
      if (repeticao > 0) {
        printf("S\n");
      } else {
        printf("N\n");
      }
      break;

    case 5:
      repeticao = 0;
      for (int l = 0; l < 9; l++) {
        for (int c1 = 0; c1 < 9; c1++) {
          for (int c2 = c1 + 1; c2 < 9; c2++) {
            if (sudoku[l][c1] == sudoku[l][c2]) {
              repeticao = 1;
            }
          }
        }
      }
      int repeticao_coluna = 0;
      for (int c = 0; c < 9; c++) {
        for (int l1 = 0; l1 < 9; l1++) {
          for (int l2 = l1 + 1; l2 < 9; l2++) {
            if (sudoku[l1][c] == sudoku[l2][c]) {
              repeticao_coluna = 1;
            }
          }
        }
      }
      int repeticao_quadrante = 0;
      int linha_inicio = 0;
      do {
        for (int l = linha_inicio; l < linha_inicio + 3; l++) {
          for (int c = 0; c < 9; c++) {
            for (int ll = linha_inicio; ll < linha_inicio + 3; ll++) {
              for (int cc = 0; cc < 9; cc++) {
                if (l != ll || c != cc) {
                  if (sudoku[l][c] == sudoku[ll][cc]) {
                    repeticao_quadrante = 1;
                  }
                }
              }
            }
          }
        }
        linha_inicio = linha_inicio + 3;
      } while (linha_inicio < 9);

      if (repeticao > 0 || repeticao_coluna > 0 || repeticao_quadrante > 0) {
        printf("S\n");
      } else {
        printf("N\n");
      }
      break;

    default:
      for (int l = 0; l < 9; l++) {
        if (l == 3 || l == 6) {
          printf("\n");
        }
        for (int c = 0; c < 9; c++) {
          if (c == 3 || c == 6) {
            printf(" ");
          }
          printf("%d ", sudoku[l][c]);
        }
        printf("\n");
      }
      break;
    }
  } while (op != 0);

  return 0;
}
