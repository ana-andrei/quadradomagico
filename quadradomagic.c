#include <stdio.h>

int main(void) {
  int m[4][4];//entrada de dados
  int s [10];//somas linha, coluna, diag p, diap s
  int l, c;
  //inicializar vetor com as somas
  int repetido=0, valteste=0;


  for(l=0; l<10;l++)
    s[l]=0;
  //entrada de dados
  for(l=0;l<4;l++){
    //roda 4x
    for(c=0;c<4;c++){
      //roda 16x
      printf("Digite o valor de m[%d][%d] = ", l, c);
      scanf("%d", &m[l][c]);
      s[l]+=m[l][c];//soma cada linha
      s[4+c] += m[l][c];//soma de cada coluna
    }
    s[8] += m[l][l];//siagonal p sendo somada
    s[9] +=m[l][3-l];//diagonal secundaria sendo somada
  }

  c=0;//flag
  for(l=1; c==0 && l<10; l++)
    if(s[0] !=s[l])
    c++;

  if(c == 0){
    //pode ser um quadrado magico
    //verificar se o numero e repetido

    for(int k =0; k<4; k++){
      for(int w=0; w<4; w++){
      int valteste= m[k][w];
        for( l=0;l<4; l++){
          for(int c=0; c<4 ; c++){
            if(m[l][c]==valteste)
            repetido++;
          }
        }
      }
    }

    if(repetido == 4 * 4 ){
      printf("\nNÃO há numeros repetidos na matriz\n");
      printf("É um quadrado mágico");
    }
    else{
      printf("Não é um quadrado magico");
    }

  }
    else
    printf("NÃO é um quadrado mágico");

  return 0;
}