#include "descompactador.h" 
#include "bitmap.h"

int main(int argc, char const *argv[]) {
    short int n;
    char lixo;        
    char c; // aux do ponteiro de arquivo
    bitmap bm = bitmapInit(1024);
    FILE* fp = fopen(argv[1],"rb"); //abrindo arquivo    
    if(fp != NULL){
        printf("tell = %ld\n", ftell(fp));
        fread(&n,sizeof(short int),1,fp); // le o num de bytes de cabecalho
        printf("n bytes = %d\n", n);    
        fread(&lixo,sizeof(unsigned char),1,fp); // le o num de bits de lixo do cabecalho
        printf("lixo = %d\n", lixo);    
        for(int i = 0; i < n; i++){ // le o cabecalho e armazena no bitmap bm
        // printf("tell = %ld\n", ftell(fp));
            unsigned char c;
            fread(&c,sizeof(unsigned char),1,fp);
            printf("entrei no primeiro - ");        
            printf("%d - ", c);
            for(int j = 7; j >= 0; j--){
                printf("%d", (c>>j)&1);
                bitmapAppendLeastSignificantBit(&bm,(c>>j)&1);
            }
            printf("\n");
        }           
        printf("tell = %ld\n", ftell(fp));        

    int p = 0;
    Arv* reconst = reconstroi_arv(&bm, &p);
    // arv_imprime(reconst); //debug

    free(bitmapGetContents(bm));
    bm = bitmapInit(1024); // reinicia o bitmap p/ leitura da codificacao    

    FILE* descompactado = fopen("descompactado","w");    
    int z = 0;
    Arv* aux = reconst;        
    while(!feof(fp)){ // le o resto do arquivo (parte da codificaçao, nao deveria ler o cabecalho novamente)
        // ERRO -> ESTA LENDO ALGUMAS INFORMAÇOES REPETIDAS, MAS O PONTEIRO É ATUALIZADO POR FREAD() !! (DEBUGUEI COM FTELL())
    // printf("tell = %ld\n", ftell(fp));
        unsigned char c;
        fread(&c,sizeof(unsigned char),1,fp);        
        printf("entrei no segundo - ");        
        printf("%d - ", c);
        for(int j = 7; j >= 0; j--){            
            printf("%d", (c>>j)&1);
            bitmapAppendLeastSignificantBit(&bm,(c>>j)&1);
        }        
        printf("\n");
    }
        printf("tell = %ld\n", ftell(fp));
    // escrever no arquivo    
    // fclose(descompactado);
    // int i;
    // for (i=0; i< bitmapGetLength(bm); i++) {      
	//   printf("bit #%d = %0xh\n", i, bitmapGetBit(bm, i));
	// }
    // printf("%d\n",bitmapGetLength(bm));
    // printf("FIM DO DEBUG BITMAP\n");
    // printf("%d\n", n);
    }
    
    return 0;
}