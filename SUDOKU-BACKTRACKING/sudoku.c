#include <stdio.h>

void io(int puzzle[][9], int n, int f)
{
  int i, j;

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(f) scanf("%d", &puzzle[i][j]);
      else  printf("%d ", puzzle[i][j]);
    }
    if(!f)
      printf("\n");
  }
}
/* i e j representam a linha e a coluna, respectivamente
da célula que queremos preencher com o número x */

// puzzle matriz onde se encontra o sudoku</pre>
int isPossible(int i, int j, int puzzle[][9], int x)
{
    int l, k, lin, col;
    for(k = 0; k < 9; k++)
    {
        if(puzzle[k][j] == x) return 0; // procura na colula j
        if(puzzle[i][k] == x) return 0; // procura na linha i
    }

    lin = (i / 3) * 3; /* essa operação fornece a linha
                        da primeira célula do quadrante*/
    col = (j / 3) * 3; /* essa operação fornece a coluna
                        da primeira célula do quadrante*/
    // procura na sub grade
    for(l = lin; l < lin+3; l++)
    {
        for(k = col; k < col+3; k++)
        {
            if(puzzle[l][k] == x)
                return 0;
        }
    }
    return 1;
}
int solve(int puzzle[][9], int i, int j)
{
    int x, lin, col;
    col = j; lin = i;

    if(i == 9) // Econtramos uma solução
        return 1;

    // 1
    if(col < 8) col++;
    else
    {
        lin++;
        col = 0;
    }

    // 2
    if(puzzle[i][j]) return solve(puzzle, lin, col);
    else
    {
        for(x = 1; x <= 9; x++) // 2.1
        {
            if(isPossible(i, j, puzzle, x))
            {
                puzzle[i][j] = x;
                // 3
                if(solve(puzzle, lin, col)) return 1;
                puzzle[i][j] = 0;
            }
        }
    }
    return 0; // não encotramos solução
}

int main(void)
{
  int n, x;
  n = 9;

  int puzzle[9][9];
  io(puzzle, n, 1);

  x = solve(puzzle, 0, 0);
  if(x) io(puzzle, n, 0);
  else printf("Nao existe solucao\n");

  return 0;
}
