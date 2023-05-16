#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define MAP_1_WIDTH 15
#define MAP_1_HEIGHT 15
#define MAP_2_WIDTH 30
#define MAP_2_HEIGHT 30

void delay(int segundos)
{
	int milli_seconds = 1000 * segundos;
	
	clock_t start_time = clock();
	
	while (clock() < start_time + milli_seconds);
	
}

int vida = 3;
void MENU_1();
void DRAW_MAP_1();
void DRAW_MAP_2();
void TUTORIAL();
void menu();
void MAP_2();

int player_x = 1;
int player_y = 1;
int has_key = 0;
int has_key2 = 0;

char status[100];

/*############### MAPA 1 ###############*/

char map_1[MAP_1_HEIGHT][MAP_1_WIDTH] = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', '*', ' ', '*', ' ', '*', '*', '*', '*', '*', '*', ' ', '*'},
    {'*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'},
    {'*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'},
    {'*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'},
    {'*', ' ', '*', '*', '*', '*', ' ', '*', '*', '*', ' ', ' ', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

void DRAW_MAP_1() {
    for (int y = 0; y < MAP_1_HEIGHT; y++) {
        for (int x = 0; x < MAP_1_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                printf("&");
            } else {
                printf("%c", map_1[y][x]);
            }
        }
        printf("\n");
    }
    printf("\t%s\n", status);
    printf("Vida: %d\n\n", vida);
}

void MAP_1() {

	map_1[13][4] = '@';
    map_1[2][14] = 'D';
	
	char input;
	
		
		while(1){
			
		system("cls || clear");
		
		DRAW_MAP_1();
		
        input = getch();
		if (map_1[player_y][player_x] == '=') {
                    MAP_2();
				}
        switch (input) {
            case 'a':
                if (map_1[player_y][player_x - 1] != '*' ) {
                    player_x--;
                }
                break;
            case 'd':
                if ((map_1[player_y][player_x + 1] != '*' ) &&
                    !(map_1[player_y][player_x] == 'D' && !has_key)) {
                    player_x++;
                }
                break;
            case 'w':
                if (map_1[player_y - 1][player_x] != '*' ) {
                    player_y--;
                }
                break;
            case 's':
                if (map_1[player_y + 1][player_x] != '*' ) {
                    player_y++;
                }
                break;
            case 'i':
                if (map_1[player_y][player_x] == '@') {
                    map_1[player_y][player_x] = ' ';
                    has_key = 1;
                    printf("=========================\n// Voce pegou a chave! //\n========================="); delay(1);
                    
                }
				    /*else if (map_1[player_y][player_x] == '#'){
                	vida = vida - 1;
				}*/ else if (map_1[player_y][player_x] == 'D' && has_key) {
                    map_1[player_y][player_x] = '=';
                    printf("=========================\n// Voce abriu a porta! //\n========================="); delay(1);
                    printf("\n");
                    printf("=======================\n// Ande para avancar //\n======================="); delay(2);
				}
				/*else if (map_1[player_y][player_x] == '=') {
                    MAP_2();
				}*/
                break;
        }
    }
}


/*############### MAPA 2 ###############*/

char map_2[MAP_2_HEIGHT][MAP_2_WIDTH] = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

void DRAW_MAP_2() {
    for (int y = 0; y < MAP_2_HEIGHT; y++) {
        for (int x = 0; x < MAP_2_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                printf("&");
            } else {
                printf("%c", map_2[y][x]);
            }
        }
        printf("\n");
    }
    printf("\t%s\n", status);
    printf("Vida: %d\n\n", vida);
    if(vida==0){
					system("cls || clear");
					system("color 4F");
					printf("Voce so tinha um trabalho...\nSO UM!!!\n\n"); delay(2);
					printf("Retornando pro menu..."); delay(2);
					system("color F1");
					MENU_1();
				}
}

void MAP_2() {
	map_2[13][4] = '@';
    map_2[27][29] = 'D';
	
	char input;
	
		
		while(1){
			
		system("cls || clear");
		
		DRAW_MAP_2();
		
        input = getch();

        switch (input) {
            case 'a':
                if (map_2[player_y][player_x - 1] != '*' && map_2[player_y][player_x - 1] != '#' ) {  //fisica//
                    player_x--;
                }
                else if (map_2[player_y][player_x - 1] != '*'){
				vida = vida - 1;   //dano//
				}
                break;
            case 'd':
                if ((map_2[player_y][player_x + 1] != '*' && map_2[player_y][player_x + 1] != '#' ) &&
                    !(map_2[player_y][player_x] == 'D' && !has_key)) {
                    player_x++;
                }
                else if(map_2[player_y][player_x + 1] != '*'){
				vida = vida - 1;
				}
                break;
            case 'w':
                if (map_2[player_y - 1][player_x] != '*' && map_2[player_y - 1][player_x] != '#' ) {
                    player_y--;
                }
                else if (map_2[player_y - 1][player_x] != '*'){
				vida = vida - 1;
				}
                break;
            case 's':
                if (map_2[player_y + 1][player_x] != '*' && map_2[player_y + 1][player_x] != '#'  ) {
                    player_y++;
                }
                else if (map_2[player_y + 1][player_x] != '*'){
				vida = vida - 1;
				}
                break;
            case 'i':
                if (map_2[player_y][player_x] == '@') {
                    map_2[player_y][player_x] = ' ';
                    has_key = 1;
                    printf("=========================\n// Voce pegou a chave! //\n========================="); delay(1);
                    
                }
				    /*else if (map_2[player_y][player_x] == '#'){
                	vida = vida - 1;
				}*/ else if (map_2[player_y][player_x] == 'D' && has_key) {
                    map_2[player_y][player_x] = '=';
                    printf("=========================\n// Voce abriu a porta! //\n========================="); delay(1);
				}
    }
}
}
void TUTORIAL(){
	
	system("cls || clear");
	
	printf("TUTORIAL:"); 
	
	printf("\n\n JOGO:\n\n"); 
	printf(" O jogo eh do estilo aventura/puzzle onde o objetivo eh o jogador conseguir passar de tres fases. Em cada fase o jogador deve se\n"); 
	printf(" movimentar para pegar uma chave para abrir a porta fechada.\n"); 
	printf(" O jogador possui os seguintes comando:\n\n"); 
	printf("     W: O jogador movimenta uma unidade para cima;\n\n"); 
	printf("     A: O jogador movimenta uma unidade para esquerda;\n\n"); 
	printf("     S: O jogador movimenta uma unidade para baixo;\n\n");
	printf("     D: O jogador movimenta uma unidade para direita;\n\n");
	printf("     I: O jogador interage com o objeto que esta em cima.\n\n");
	
	printf("\n O jogo possui os seguintes elementos nas fases:\n\n");
	
	printf("     &: Simbolo que representa o jogador.\n\n");
	printf("     *: Simbolo que representa uma parede, o jogador ao se movimentar nao pode passar pela parede.\n\n");
	printf("     @: Simbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage\n");
	printf("     com a chave.\n\n");
	printf("     D: Simbolo que representa a porta fechada.\n\n");
	printf("     =: Simbolo que representa a porta aberta quando o jogador interage com a chave.\n\n");
	printf("     O: Simbolo que representa um botao que o usuario pode interagir, o botao fica no chao e o jogador deve ficar em cima dele\n");
	printf("     para poder interagir.\n\n");
	printf("     #: Simbolo que representa um espinho. A fase eh reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada\n");
	printf("     tres vezes, o jogo volta para o menu principal.\n\n");
	printf("     >: Simbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele\n");
	printf("     eh transportado para o outro e vice-versa.\n\n");
	printf("     ¬: Simbolo que representa o monstro nivel 1. O mostro tem um movimento aleatorio, logo, ele movimenta um bloco para\n");
	printf("     cima ou para direita ou para esquerda ou para baixo. O monstro sempre faz uma movimentacao depois do usuario se\n");
	printf("     movimentar ou interagir com um objeto.\n\n");
	printf("     K: Simbolo que representa o monstro nivel 2. O mostro nivel dois tem uma inteligencia de se movimentar na direcao do\n");
	printf("     jogador. O monstro nao precisa saber desviar de obstaculos, ele sempre vai andar em linha reta em direcao do jogador.\n\n");
	
	printf("Deseja retornar ao menu?(1:Sim   2: Nao)");
			int mn;
			scanf("%i", &mn);
			if (mn == 1){
				MENU_1();
            }
            else {
            	TUTORIAL();
			}
			

            
}

void MENU_1(){
	int escolha = 0;
	do{
	system("cls || clear");
	printf("Menu\n 1: Jogar\n 2: tutorial\n 3: Sair\n");
	printf("Selecione o jogo desejado: ");
	
	scanf("%i", &escolha);
	if (escolha == 1){
		MAP_1();
	}
	if (escolha == 2){
		TUTORIAL();
	}
	if (escolha == 3){
		printf("Saindo do aplicativo...");
		exit (0);
	}
}
	while(escolha != 0);
}

int main(){
	system("color F1");
	//intro();
	MENU_1();
}
