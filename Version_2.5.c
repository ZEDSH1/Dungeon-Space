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

int player_x = 1;
int player_y = 1;
int has_key = 0;
int has_key2 = 0;
int direction = 0;
int vida = 3;

typedef struct{
	int monster_x;
	int monster_y;
	int direction;
}Monster;

Monster monster1A;
Monster monster1B;

void MENU_1(){
	int escolha = 0;
	do{
	system("cls || clear");
	printf("Menu\n 1: Jogar\n 2: tutorial\n 3: Sair\n");
	printf("Selecione o jogo desejado: ");
	
	scanf("%i", &escolha);
	if (escolha == 1){
		MAP_2();
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
	printf("     Â¬: Simbolo que representa o monstro nivel 1. O mostro tem um movimento aleatorio, logo, ele movimenta um bloco para\n");
	printf("     cima ou para direita ou para esquerda ou para baixo. O monstro sempre faz uma movimentacao depois do usuario se\n");
	printf("     movimentar ou interagir com um objeto.\n\n");
	printf("     K: Simbolo que representa o monstro nivel 2. O mostro nivel dois tem uma inteligencia de se movimentar na direcao do\n");
	printf("     jogador. O monstro nao precisa saber desviar de obstaculos, ele sempre vai andar em linha reta em direcao do jogador.\n\n");
	
	printf("Deseja retornar ao menu?\n1:Sim   2: Nao");
			int escolha;
			scanf("%i", &escolha);
			if (escolha == 1){
				MENU_1();
            }
            else {
            	TUTORIAL();
			}
			

            
}

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
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

void DRAW_MAP_1() {
	int y;
	int x;
    for (y = 0; y < MAP_1_HEIGHT; y++) {
        for (x = 0; x < MAP_1_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                printf("& ");
            } else {
                printf("%c ", map_1[y][x]);
            }
        }
        printf("\n");
    }
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
				     else if (map_1[player_y][player_x] == 'D' && has_key) {
                    map_1[player_y][player_x] = '=';
                    printf("=========================\n// Voce abriu a porta! //\n========================="); delay(1);
                    printf("\n");
                    printf("=======================\n// Ande para avancar //\n======================="); delay(2);
				}
				
                break;
        }
    }
}

/*############### MAPA 2 ###############*/
char map_2[MAP_2_HEIGHT][MAP_2_WIDTH] = {
    /*00*/{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    /*01*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#', '#', '#', '#', '#', '#', '#', '*'},
    /*02*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*03*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#', ' ', '#', '#', '#', '#', '#', '*'},
    /*04*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', 'O', '*'},
    /*05*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '*'},
    /*06*/{'*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    /*07*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*08*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*09*/{'*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*'},
    /*10*/{'*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*'},
    /*11*/{'*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*'},
    /*12*/{'*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*'},
    /*13*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*14*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*15*/{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    /*16*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*17*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*18*/{'*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*'},
    /*19*/{'*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*'},
    /*20*/{'*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*'},
    /*21*/{'*', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '*'},
    /*22*/{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*23*/{'*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    /*24*/{'*', '#', '#', '#', '#', '#', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '*'},
    /*25*/{'*', '#', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '*'},
    /*26*/{'*', '#', ' ', '#', '#', '#', '#', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '#', '#', '#', '#', ' ', '#', '*'},
    /*27*/{'*', ' ', ' ', '#', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '#', ' ', ' ', '*'},
    /*28*/{'*', ' ', '#', '#', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '#', '#', ' ', '*'},
    /*29*/{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    	  //0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   
};

void DRAW_MAP_2() {
	int y;
	int x;
    for (y = 0; y < MAP_2_HEIGHT; y++) {
        for (x = 0; x < MAP_2_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                printf("& ");
            } 
			
			else if (x == monster1A.monster_x && y == monster1A.monster_y) {
                printf("m ");
            }
            
            else if (x == monster1B.monster_x && y == monster1B.monster_y) {
                printf("m ");
            }
			
			else {
                printf("%c ", map_2[y][x]);
            }
        }
        printf("\n");
    }
    
    printf("Vida: %d\n\n", vida);
    if(vida==0){
					system("cls || clear");

					printf("Voce so tinha um trabalho...\nSO UM!!!\n\n"); delay(2);
					printf("Retornando pro menu..."); delay(2);
					vida = vida + 3; 

					MENU_1();
				}
}

void MOVE_MONSTER_1A() {
	monster1A.direction = rand() % 4;
	
    switch (monster1A.direction) {
        case 0: 
        	if (map_2[monster1A.monster_y][monster1A.monster_x - 1] != '*' && map_2[monster1A.monster_y][monster1A.monster_x - 1] != '#' ) {
                    monster1A.monster_x--;
                }
            break;
        case 1: 
        	if (map_2[monster1A.monster_y][monster1A.monster_x + 1] != '*' && map_2[monster1A.monster_y][monster1A.monster_x + 1] != '#' ) {
        		    monster1A.monster_x++;
			    }
            break;
        case 2: 
            if (map_2[monster1A.monster_y - 1][monster1A.monster_x] != '*' && map_2[monster1A.monster_y - 1][monster1A.monster_x] != '#' ) {
                    monster1A.monster_y--;
                }
            break;
        case 3:
        	if (map_2[monster1A.monster_y + 1][monster1A.monster_x] != '*' && map_2[monster1A.monster_y + 1][monster1A.monster_x] != '#'  ) {
                    monster1A.monster_y++;
                }
            break;   
    }

}

void MOVE_MONSTER_1B() {
	monster1B.direction = rand() % 4;
	
    switch (monster1B.direction) {
        case 0: 
        	if (map_2[monster1B.monster_y][monster1B.monster_x - 1] != '*' && map_2[monster1B.monster_y][monster1B.monster_x - 1] != '#' ) {
                    monster1B.monster_x--;
                }
            break;
        case 1: 
        	if (map_2[monster1B.monster_y][monster1B.monster_x + 1] != '*' && map_2[monster1B.monster_y][monster1B.monster_x + 1] != '#' ) {
        		    monster1B.monster_x++;
			    }
            break;
        case 2: 
            if (map_2[monster1B.monster_y - 1][monster1B.monster_x] != '*' && map_2[monster1B.monster_y - 1][monster1B.monster_x] != '#' ) {
                    monster1B.monster_y--;
                }
            break;
        case 3:
        	if (map_2[monster1B.monster_y + 1][monster1B.monster_x] != '*' && map_2[monster1B.monster_y + 1][monster1B.monster_x] != '#'  ) {
                    monster1B.monster_y++;
                }
            break;   
    }

}

void MAP_2() {
	player_x = 1;
	player_y = 1;
	
	monster1A.monster_x = MAP_2_WIDTH - 14;
    monster1A.monster_y = MAP_2_HEIGHT - 13;
    monster1B.monster_x = MAP_2_WIDTH - 16;
    monster1B.monster_y = MAP_2_HEIGHT - 16;
  
	map_2[28][1] = '@';
    map_2[2][29] = 'D';

	char input;
	
		
		while(1){
			
		system("cls || clear");
		
		DRAW_MAP_2();
		
        input = getch();

        switch (input) {
            case 'a':
                if (map_2[player_y][player_x - 1] != '*' && map_2[player_y][player_x - 1] != '#') {  //fisica//
                    player_x--;
                }
                else if (map_2[player_y][player_x - 1] == '#'){
				vida = vida - 1;   //dano//
				}
                break;
            case 'd':
                if ((map_2[player_y][player_x + 1] != '*' && map_2[player_y][player_x + 1] != '#') &&
                    !(map_2[player_y][player_x] == 'D' && !has_key)) {
                    player_x++;
                }
                else if(map_2[player_y][player_x + 1] == '#'){
				vida = vida - 1;
				}
                break;
            case 'w':
                if (map_2[player_y - 1][player_x] != '*' && map_2[player_y - 1][player_x] != '#') {
                    player_y--;
                }
                else if (map_2[player_y - 1][player_x] == '#'){
				vida = vida - 1;
				}
                break;
            case 's':
                if (map_2[player_y + 1][player_x] != '*' && map_2[player_y + 1][player_x] != '#') {
                    player_y++;
                }
                else if (map_2[player_y + 1][player_x] == '#'){
				vida = vida - 1;
				}
                break;
            case 'i':
                if (map_2[player_y][player_x] == '@') {
                    map_2[player_y][player_x] = ' ';
                    has_key = 1;
                    printf("=========================\n// Voce pegou a chave! //\n========================="); delay(1);                 
                }
                
                else if (map_2[player_y][player_x] == 'D' && has_key) {
                    map_2[player_y][player_x] = '=';
                    printf("=========================\n// Voce abriu a porta! //\n========================="); delay(1);
				}
				else if (map_2[player_y][player_x] == map_2[4][28] && map_2[4][28] == 'O') {
					map_2[4][28] = ' ';
					map_2[28][28] = 'O';
        			//paredes meio esquerdo
        			map_2[12][11] = ' ';
                	map_2[12][12] = ' ';
                	
                	//espinhos meio esquerdo
        			map_2[13][11] = ' ';
                	map_2[13][12] = ' ';
                	
                	//espinhos meio direito 
                	map_2[17][17] = ' ';
                	map_2[17][18] = ' ';
                	
                	//paredes meio direito 
                	map_2[18][17] = ' ';
                	map_2[18][18] = ' ';

					}
					
				else if (map_2[player_y][player_x] == map_2[28][28] && map_2[28][28] == 'O') {

              	//lado esquerdo inferior
                	map_2[24][7] = ' ';
                	map_2[24][8] = ' ';
                	map_2[25][7] = ' ';
                	map_2[25][8] = ' ';
					}								 
				}
		MOVE_MONSTER_1A();
		MOVE_MONSTER_1B();
		
		if (player_x == monster1A.monster_x && player_y == monster1A.monster_y || player_x == monster1B.monster_x && player_y == monster1A.monster_y) vida--;
    }
}

int main(){
	srand(time(NULL));
	system("color 06");
	//intro();
	MENU_1();
}
