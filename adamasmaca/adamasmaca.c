#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu(void);
void kelimehaznesi(void);
void kelimetutma(void);
void algoritma(void);
void gorsel(int);

char kelime[30];
char kategori[30];

struct liste{
    char kelime[30];
};
typedef struct liste list;

int main(){

    menu();

    return 0;
}

void menu(void){

    int a=0;

    while(a!=4){
        printf("Secim yapiniz\n ");
        printf("1.Basla\n2.Kurallar\n3.Kelime Haznesi\n4.Cikis");
        scanf("%d",&a);

        switch(a){
            case 1:
                kelimetutma();
                algoritma();
                break;
            case 2:
                printf("Kurallar:\n1.Kelime haznesine ekleme yapılabilir\n2.Her yanlis tahminde bir cizgi cizilir toplamda 11 hakkiniz vardir\n3.Ne kadar az tahminde bitirirseniz o kadar çok puan alirsiniz\n\n");
                break;
            case 3:
                kelimehaznesi();
                break;
        }
    }
}

void kelimehaznesi(void){
    list p;
    int a,i=0,secenek;
    FILE *ptr;

    printf("Kelime listesini gormek icin 1 kelime eklemek icin 2 giriniz\n");
    scanf("%d",&secenek);

    switch(secenek){

        case 1:
            ptr=fopen("kelimehaznesi.txt","r");
                while(!feof(ptr)){
                    fscanf(ptr,"%s\n",p.kelime);
                    printf("%d.%s\n",i+1,p.kelime);
                    i++;
                }
            fclose(ptr);
        break;
        case 2:
            ptr=fopen("kelimehaznesi.txt","a");
            printf("Kac kelime ekliyeceginizi yaziniz\n");
            scanf("%d",&a);
            printf("Kelime eklemesi yaparken isim - işareti ve kategori yazilmalidir Ornek: Berkay-isim\n");
            for(i=0;i<a;i++){
                printf("%d:",i+1);
                scanf("%s",p.kelime);
                fprintf(ptr,"%s\n",p.kelime);
            }
            fclose(ptr);
        break;
    }
}

void kelimetutma(void){

    int i=0,s=0;
    FILE *ptr;
    ptr=fopen("kelimehaznesi.txt","r");
    list p;

    while(!feof(ptr)){
        fscanf(ptr,"%s\n",p.kelime);
        i++;
    }
    unsigned int a=(unsigned int)time(NULL);
    srand(a);

    int random_num=rand()%i+1;
    rewind(ptr);
    i=0;
    for(;i<random_num;i++){
        fscanf(ptr,"%s\n",p.kelime);
    }
    fscanf(ptr,"%s\n",p.kelime);
    for(i=0;p.kelime[i]!='-';i++){
        kelime[i]=p.kelime[i];
    }
    i++;
    for(;p.kelime[i]!='\0';i++){
        kategori[s]=p.kelime[i];
        s++;
    }

}
void algoritma(void){

    int i=0,b=0,uzunluk=0,d,e,l=0,puan=0;
    char a,temple[30];
    while(kelime[i]!='\0'){
        uzunluk++;
        i++;
    }
    i=0;
    while(uzunluk>0){
        temple[i]='_';
        i++;
        uzunluk--;
    }

    for(i=0;i<11;i++){
        printf("Harf tahmini yapiniz  ");
        scanf("\n%c",&a);
        while(kelime[b]!='\0'){
            if(a==kelime[b]){
                i--;
                temple[b]=a;
                puan+=30;
                printf("+30 Puan\n");

            }
            b++;
        }
        for(d=0;temple[d]!='-';d++){
                printf("%c ",temple[d]);
            }
            printf("  Kategori: %s\n",kategori);
            printf("\n\n");
            gorsel(i);
            printf("\n");
        b=0;
        for(e=0;temple[e]!='\0';e++){
            if(temple[e]=='_')
                l++;
        }
        if(l==0){
            puan+=(11-i)*30;
            printf("Tebrikler Kazandiniz!!\n");
            printf("Puaniniz: %d\n",puan);
            break;
        }
        l=0;
    }
    if(i==11){
    printf("Maalesef Kaybettiniz :(\n");
    printf("Puaniniz: %d\n",puan);
    }

}
void gorsel(int a){

    switch(a){

        case 0:
            printf(" __");
            break;

        case 1:
            printf("  | \n  | \n _|_");
            break;

        case 2:
            printf("  | \n  | \n  | \n  | \n  | \n _|_");
            break;

        case 3:
            printf("  -------   \n  | \n  | \n  | \n  | \n _|_");
            break;

        case 4:
            printf("  -------   \n  |     | \n  | \n  | \n  | \n _|_");
            break;

        case 5:
            printf("  -------   \n  |     | \n  |     O \n  | \n  | \n _|_");
            break;

        case 6:
            printf("  -------   \n  |     | \n  |     O \n  |     | \n  |     |\n _|_");
            break;
        case 7:
            printf("  -------   \n  |     | \n  |     O \n  |    /| \n  |     |\n _|_");
            break;

        case 8:
            printf("  -------   \n  |     | \n  |     O \n  |    /|\\  \n  |     |\n _|_");
            break;

        case 9:
            printf("  -------   \n  |     | \n  |     O \n  |    /|\\  \n  |     |\n _|_   /");
            break;

        case 10:
            printf("  -------   \n  |     | \n  |     O \n  |    /|\\  \n  |     |\n _|_   / \\");
            break;
    }
}