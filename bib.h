#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>





extern const int width;
extern const int height;
extern const int board_size;
extern const int menu_tab_size;
extern SDL_Rect machine_tab;
extern SDL_Rect menu_tab;
extern SDL_title1;
extern SDL_title2;
extern SDL_title3;
extern SDL_Rect player_tab;
extern SDL_Rect record_tab;
extern SDL_Rect resume;
extern SDL_Rect back_to_menu;
extern SDL_Rect Exit;
extern SDL_Rect back_tab;
extern SDL_Rect pause_button;
extern SDL_Rect board;
extern SDL_Rect newgame;
extern SDL_Rect continue_retry;
extern SDL_Rect end;
extern SDL_Rect restart;
extern SDL_Rect interro;


typedef struct pos
{
    int x;
    int y;
}pos;
typedef struct color
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
}color;

//c
void init_lvl(int *nbrdiagonal,int *size,pos* pos_insert,pos* pos_init,pos * pos_final,int matrice[8][8]);
void reset(int matrice [8][8],int nbrligne,int nbrcolomn);
void affich_matrice(int matrice[8][8],int nbrligne,int nbrcolomn);
void add_diagonals(int matrice[8][8],int nbrdiagonal,int nbrligne,int nbrcolomn);
pos randomizePosInit(int size);
pos move_left(pos pos_final);
pos move_right(pos pos_final);
pos move_up(pos pos_final);
pos move_down(pos pos_final);
pos NavigateMatrix(int matrice[8][8],pos pos_init,int size );
bool verif(pos pos_insert,pos pos_init);
bool pos_insert_valide(pos pos_insert,int size);
//SDL
bool Initialize(void);
bool withinrec(SDL_Event event,SDL_Rect rect);
void menu();
void makeGrid(int n);
void SDL_Pos(int size);
void playmode_background(int n);
void record_tab_background(int n);
void continue_end ();
void restart_end(int n);
void win_lose_background();
void SDL_addiagonals(SDL_Renderer *renderer,int matrice[8][8],int size/*size of matrice*/);
void diagonal_1(int i, int j, int size);
void diagonal_2(int i, int j,int size);
pos Get_pos(SDL_Event event,int size);//listens for a click on one of the cases and gives the corresponding pos
void Render_pos(pos position,int size,Uint8 r,Uint8 g,Uint8 b,Uint8 alpha);//takes a pos variable and renders the corresponding rectangle case
void load_lvl(int *size,int *partie,bool win,int *tries,int matrice,pos *pos_init,pos* pos_final,Uint32* startTime,pos *pos_insert,int *score);
color get_color(int x,int y);
void machine_creat_matrice(int matriceM[8][8],int size);
void Shutdown(void);


#endif // BIB_H_INCLUDED
