#include <stdio.h>
#include <TIME.H>
#include <stdlib.h>

int main(){

    int chance_magikarp, chance_dratini, chance_nidoran, chance_gyarados, chance_mewtwo,
    poke_select, bola_select,  fruta_select, numero_aleatorio, finalizar, nova_tentativa;

    float pokebola, grande_bola, ultra_bola, berry_comum, berry_dourada, chance, chance_fuga;

    chance_magikarp = 75; chance_dratini = 35; chance_nidoran = 55; chance_gyarados = 20; chance_mewtwo = 8; pokebola = 1;
    grande_bola = 1.2; ultra_bola = 1.5; berry_comum = 1.1; berry_dourada = 1.5; finalizar = 0;

    do {
        printf("Escolha um Pokemon:\n1- Magikarp\n2- Dratini\n3- Nidoran\n4- Gyarados\n5- Mewtwo\n");
        scanf("%d", &poke_select);
            if (poke_select > 5 || poke_select < 1)
                printf ("Escolha um valor entre 1 e 5\n\n");
    }   while (poke_select < 1 || poke_select > 5);

        switch (poke_select)
        {
            case 1:
            printf ("Um Magikarp apareceu!\n");
            chance = chance_magikarp;
            break;

            case 2:
            printf ("Um Dratini apareceu!\n");
            chance = chance_dratini;
            break;

            case 3:
            printf ("Um Nidoran apareceu!\n");
            chance = chance_nidoran;
            break;

            case 4:
            printf ("Um Gyarados apareceu!\n");
            chance = chance_gyarados;
            break;

            case 5:
            printf ("Um Mewtwo apareceu!\n");
            chance = chance_mewtwo;
            break;
        };

    do {
        printf("\nEscolha uma Pokebola:\n1- Pokebola\n2- Grande Bola\n3- Ultrabola\n");
        scanf("%d", &bola_select);
            if (bola_select > 3 || bola_select < 1)
                printf ("Escolha um valor entre 1 e 3\n\n");
    }   while (bola_select < 1 || bola_select > 5);

        switch (bola_select)
        {
            case 1:
                printf ("Pokebola Selecionada!\n");
                chance = chance * pokebola;
                break;

                case 2:
                printf ("Grande Bola Selecionada!\n");
                chance = chance * grande_bola;
                break;

                case 3:
                printf ("Ultrabola Selecionada!\n");
                chance = chance * ultra_bola;
                break;
        };

    do {
        printf("\nUsar Frutas?\n1- Berry Comum\n2- Berry Dourada\n3- Nao usar\n");
        scanf("%d", &fruta_select);
            if (fruta_select < 1 || fruta_select > 3)
                printf ("Escolha um valor entre 1 e 3\n\n");
    }   while (fruta_select < 1 || fruta_select > 3);

        switch (fruta_select)
        {
            case 1:
                printf ("\nBerry comum selecionada!\n");
                chance = chance * berry_comum;
                break;

                case 2:
                printf ("\nBerry Dourada Selecionada!\n");
                chance = chance * berry_dourada;
                break;

                case 3:
                printf ("\nNenhuma fruta selecionada!\n");
                break;
        };

    chance_fuga = ((100 - chance)*0.1);

    do {
            printf("\nJogando");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");
            Sleep(2500);

            {
                srand(time(NULL));
                numero_aleatorio = rand()%100;
            };

            if (numero_aleatorio <= chance){
                printf("O Pokemon foi capturado!!");
                finalizar = 1;
            }
            else{

                if (numero_aleatorio >= (100 - chance_fuga)){
                    printf("\nAh nao, o Pokemon fugiu :(");
                    finalizar = 1;
                }

                else{
                    printf("\nO Pokemon escapou! Tentar novamente? (1 - SIM / 2 - NAO)");
                    scanf("%d", &nova_tentativa);

                        if (nova_tentativa == 1){
                        finalizar = 0;
                        }

                        else{
                        finalizar = 1;
                        }
                }
            }
        } while (finalizar == 0);


    printf("\n\n\n\n//Comentarios de Controle: %d\n%f\n%f%d\n//", numero_aleatorio, chance, chance_fuga, finalizar);

     return 0;
}
