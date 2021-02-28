#include <stdio.h>
#include <stdlib.h>
#define N 7

int diagrama[N][N] = //criamos a matriz com os dados iniciais, deixando os lugares vazios como 0
        {
                {0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 4, 5, 0},
                {0, 0, 4, 0, 0, 0, 0},
                {0, 0, 0, 6, 0, 0, 1},
                {0, 4, 0, 0, 5, 0, 0},
                {0, 0, 0, 0, 0, 1, 0},
                {0, 0, 1, 3, 0, 0, 4}
        };

void desenhodiagrama() //foi criada esta funcao para pedir ao programa desenhar um tabuleiro, mantendo bordas nos retangulos de 3x2
//e trocando os zeros da matriz por um espaco vazio
{
    int i,j;
    printf("+-------------------------------+\n");
    for (i = 1; i <= N-1; i++)
    {
        printf("|");
        for (j = 1; j <= N-1; j++)
        {
            if (diagrama[i][j] != -1)
                printf("  %d  ", diagrama[i][j]);
            else
                printf(" ");
            if (j %3 == 0 || j == N-1)
                printf("|");
        }
        if (i %2 == 0 || i == N-1)
            printf("\n+-------------------------------+");
        printf("\n");
    }
}

int Rokudoku(int i, int j, int k) //aqui foi criada a funcao rokudoku para a resolucao do tabuleiro
{
    int coluna,linha, linha_start, linha_end, coluna_start, coluna_end, counter;

    for (linha = 1; linha <= N-1; linha++)
        if (diagrama[linha][j] == k){
            printf("\n Coluna invalida \n");
            return -1;
        }

    for (coluna = 1; coluna <= N-1; coluna++)
        if (diagrama[i][coluna] == k){
            printf("\n Linha invalida \n");
            return -2;
        }

    //verificando se a linha é par ou ímpar
    float div = i % 2;
    // se for ímpar eu busco nesta linha e na linha de baixo
    if(div != 0){
        linha_start = i;
        linha_end = i+1;

        // se for par eu busco nesta linha e na linha de cima
    } else {
        linha_start = i;
        linha_end = i-1;
    }
    // se a coluna for menor que 4, eu começo na primeira coluna e ando + 2 casas
    if(j < 4)
        coluna_start = 1;
    else
        // senao eu começo na coluna 4 e ando + 2 casas
        coluna_start = 4;

    //alterno a linha manualmente pois são só duas
    linha = linha_start;
    coluna = coluna_start;
    //alterno a coluna com o for
    for(counter = 0; counter < 3; counter ++){
        // para debug descomente a linha abaixo
        // printf("\n Linha = %d Coluna = %d\n", linha,coluna);
        if (diagrama[linha][coluna] == k){
           printf("\n Celula invalida \n");
           return -3;
        }
        coluna++;
    }

    //alterno a linha manualmente pois são só duas
    linha = linha_end;
    coluna = coluna_start;
    //alterno a coluna com o for
    for(counter = 0; counter < 3; counter ++){
        // para debug descomente a linha abaixo
        // printf("\n Linha = %d Coluna = %d\n", linha,coluna);
        if (diagrama[linha][coluna] == k) {
            printf("\n Celula invalida \n");
            return -3;
        }
        coluna++;
    }

    if (diagrama[i][j] != 0){
        printf("\n Posicao ja preenchida \n");
        return -4;
    }

    return 1;
}

int main()
{
    int coluna,linha,i,j,k,num,m,n,p;

    desenhodiagrama();
    while(1)
    {
        printf("\nInserir valor da linha: \n");
        scanf("%d", &linha);
        printf("\nInserir valor da coluna: \n");
        scanf("%d", &coluna);
        printf("\nInserir valor da posicao: \n");
        scanf("%d", &k);

        num=Rokudoku(linha, coluna, k);

        while(num<0)
        {
            printf("\nValores invalidos\n");
            printf("Inserir valor da linha: \n");
            scanf("%d", &linha);
            printf("\nInserir valor da coluna: \n");
            scanf("%d", &coluna);
            printf("\nInserir valor na posicao: \n");
            scanf("%d", &k);
            num=Rokudoku(linha, coluna, k);
        }

        diagrama[linha][coluna] = k;
        desenhodiagrama();
        p = 0;
        for(m = 1; m <= N; m++)
            for(n = 1; n <= N; n++)
                if (diagrama[m][n] == 0)
                    p++;
        if (p == 0)
            break;
    }

    return 0;
}
