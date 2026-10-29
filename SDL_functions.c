#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "C:\Users\labba\Desktop\V4\bib.h"
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>


const int width = 1000;
const int height = 785;
const int board_size = 450;
const int menu_tab_size = 100;

SDL_Rect machine_tab =
{
    .x = width / 2 - 160,
    .y = (height / 2 ) +40,
    .h = 100,
    .w = 300,
};

SDL_Rect player_tab =
{
    .x = (width / 2) -160,
    .y = (height / 2 )-50 -40,
    .h = 100,
    .w = 300,
};

SDL_Rect record_tab =
{
    .x = width/2 - 160,
    .y = height/2 +40 +100 +30,
    .h = 100,
    .w = 300,
};
SDL_Rect back_tab =
{
    .x = 5,
    .y = 5,
    .h = 50,
    .w = 50,
};

SDL_Rect rect =
{
    .x = 1000/2-500,
    .y = 785/2-450,
    .h = 100,
    .w = 300,
};

SDL_Rect pause_button=
{
    .x=946,
    .y=10,
    .h=40,
    .w=40,
    };

SDL_Rect board=
    {
        .x=width/2 - board_size/2,
        .y=height/2 - board_size/2  +50,
        .h = board_size,
        .w = board_size,
    };

SDL_Rect continue_retry=
    {
        .x=1000-115,
        .y=785-65,
        .h=50,
        .w=100,
    };

SDL_Rect title =
{
        .x=1000/2-380,
        .y=785/2-340,
        .h=200,
        .w=400,
    };
SDL_Rect title1 =
{
        .x=1000/2-345,
        .y=785/2-320,
        .h=200,
        .w=400,
    };
SDL_Rect title3 =
{
        .x=1000/2-360,
        .y=785/2-400,
        .h=200,
        .w=400,
    };

    SDL_Rect title2 =
{
        .x=1000/2-280,
        .y=785/2-320,
        .h=200,
        .w=400,
    };
SDL_Rect title4 =
{
        .x=1000/2-380,
        .y=785/2-370,
        .h=200,
        .w=400,
    };
SDL_Rect end =
    {
        .x=1000/2 -320,
        .y=785/2,
        .h=100,
        .w=300,
    };
SDL_Rect restart =
{
        .x=1000/2 +20,
        .y=785/2,
        .h=100,
        .w=300,
    };

SDL_Rect back_to_menu =
{
    .x = width / 2 - 160,
    .y = (height / 2 ) +40,
    .h = 100,
    .w = 300,
};

SDL_Rect resume =
{
    .x = (width / 2) -160,
    .y = (height / 2 )-50 -40,
    .h = 100,
    .w = 300,
};

SDL_Rect Exit =
{
    .x = width/2 - 160,
    .y = height/2 +40 +100 +30,
    .h = 100,
    .w = 300,
};
SDL_Rect rules=
{
    .x = 1000/2-500,
    .y = 785/2-450,
    .h = 100,
    .w = 300,
};
SDL_Rect interro =
{
    .x = 1000-55,
    .y = 5,
    .h = 50,
    .w = 50,
};




SDL_Window* window=NULL;
SDL_Renderer *renderer=NULL;


bool Initialize(void)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
      fprintf(stderr,"error SDL : %s\n",SDL_GetError())  ;
      return false;
    }
    window = SDL_CreateWindow("JEUX MEMOIRE",SDL_WINDOWPOS_CENTERED
                                        ,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);

        if (!window){
            return false;
        }


    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer){
        return false;
    }

     if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        fprintf(stderr, "Error initializing SDL_image: %s\n", IMG_GetError());
        return false;
    }


    return true;
}


void menu()
{
    SDL_SetRenderDrawColor(renderer,240,219,170,0.8);    //set it to green
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    //title
    SDL_Surface *title_s=IMG_Load("image/title.png");
    SDL_Texture *title_t=SDL_CreateTextureFromSurface(renderer,title_s);
    SDL_QueryTexture(title_t,NULL,NULL,&title.w,&title.h);
    SDL_RenderCopy(renderer, title_t, NULL, &title);
    //machine mode
    SDL_Surface *machinemode_s=IMG_Load("image/machinemode.png");
    SDL_Texture *machinemode_t=SDL_CreateTextureFromSurface(renderer,machinemode_s);
    SDL_QueryTexture(machinemode_t,NULL,NULL,&machine_tab.w,&machine_tab.h);
    SDL_RenderCopy(renderer, machinemode_t, NULL, &machine_tab);
    //player mode
    SDL_Surface *playermode_s=IMG_Load("image/playermode.png");
    SDL_Texture *playermode_t=SDL_CreateTextureFromSurface(renderer,playermode_s);
    SDL_QueryTexture(playermode_t,NULL,NULL,&player_tab.w,&player_tab.h);
    SDL_RenderCopy(renderer, playermode_t, NULL, &player_tab);
    //recordtab
    SDL_Surface *recordmode_s=IMG_Load("image/recordmode.png");
    SDL_Texture *recordmode_t=SDL_CreateTextureFromSurface(renderer,recordmode_s);
    SDL_QueryTexture(recordmode_t,NULL,NULL,&record_tab.w,&record_tab.h);
    SDL_RenderCopy(renderer, recordmode_t, NULL, &record_tab);
    //help button
    SDL_Surface *interro_s=IMG_Load("image/help.png");
    SDL_Texture *interro_t=SDL_CreateTextureFromSurface(renderer,interro_s);
    SDL_QueryTexture(interro_t,NULL,NULL,&interro.w,&interro.h);
    SDL_RenderCopy(renderer, interro_t, NULL, &interro);
    //render present
    SDL_RenderPresent(renderer);


}
void help()
{
    SDL_SetRenderDrawColor(renderer,240,219,170,0.8);    //set it to beige
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    //title
    SDL_Surface *title3_s=IMG_Load("image/how_to_play.png");
    SDL_Texture *title3_t=SDL_CreateTextureFromSurface(renderer,title3_s);
    SDL_QueryTexture(title3_t,NULL,NULL,&title3.w,&title3.h);
    SDL_RenderCopy(renderer, title3_t, NULL, &title3);
    //rules
    SDL_Surface *rules_s=IMG_Load("image/rules.png");
    SDL_Texture *rules_t=SDL_CreateTextureFromSurface(renderer,rules_s);
    SDL_QueryTexture(rules_t,NULL,NULL,&rules.w,&rules.h);
    SDL_RenderCopy(renderer, rules_t, NULL, &rules);
    //back
    SDL_Surface *back_s=IMG_Load("image/back.png");
    SDL_Texture *back_t=SDL_CreateTextureFromSurface(renderer,back_s);
    SDL_QueryTexture(back_t,NULL,NULL,&back_tab.w,&back_tab.h);
    SDL_RenderCopy(renderer, back_t, NULL, &back_tab);
}



bool withinrec(SDL_Event event,SDL_Rect rect)
{



    bool within=false;


    int mouseX, mouseY;
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        mouseX = event.button.x;
        mouseY = event.button.y;
    }
   if (mouseX>=rect.x && mouseX<=rect.x+rect.w
        &&mouseY>=rect.y && mouseY<=rect.y+rect.h)

        within=true;


    return within;
}


void playmode_background(int n){

    //background color
    SDL_SetRenderDrawColor(renderer,240,219,170,0.8);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    //backround ta3 grille
    SDL_SetRenderDrawColor(renderer, 233    ,   196,	106,    255  );
    SDL_RenderFillRect(renderer,&board);
    //pause button
    SDL_Surface *pause_s=IMG_Load("image/pause.png");
    SDL_Texture *pause_t=SDL_CreateTextureFromSurface(renderer,pause_s);
    SDL_QueryTexture(pause_t,NULL,NULL,&pause_button.w,&pause_button.h);
    SDL_RenderCopy(renderer, pause_t, NULL, &pause_button);
    //continue/retry button
    SDL_Surface *continue_retry_s=IMG_Load("image/continue_retry.png");
    SDL_Texture *continue_retry_t=SDL_CreateTextureFromSurface(renderer,continue_retry_s);
    SDL_QueryTexture(continue_retry_t,NULL,NULL,&continue_retry.w,&continue_retry.h);
    SDL_RenderCopy(renderer, continue_retry_t, NULL, &continue_retry);
    //home button
    SDL_Surface *back_s=IMG_Load("image/home.png");
    SDL_Texture *back_t=SDL_CreateTextureFromSurface(renderer,back_s);
    SDL_QueryTexture(back_t,NULL,NULL,&back_tab.w,&back_tab.h);
    SDL_RenderCopy(renderer, back_t, NULL, &back_tab);


    makeGrid(n);
    SDL_Pos(n);
    }

void record_tab_background(int n)
{
    //background color
    SDL_SetRenderDrawColor(renderer,240,219,170,0.8);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    //title
    SDL_Surface *title4_s=IMG_Load("image/Record table.png");
    SDL_Texture *title4_t=SDL_CreateTextureFromSurface(renderer,title4_s);
    SDL_QueryTexture(title4_t,NULL,NULL,&title4.w,&title4.h);
    SDL_RenderCopy(renderer, title4_t, NULL, &title4);
    //back
    SDL_Surface *back_s=IMG_Load("image/back.png");
    SDL_Texture *back_t=SDL_CreateTextureFromSurface(renderer,back_s);
    SDL_QueryTexture(back_t,NULL,NULL,&back_tab.w,&back_tab.h);
    SDL_RenderCopy(renderer, back_t, NULL, &back_tab);
    //record table
    SDL_Surface *rect_s=IMG_Load("image/rect.png");
    SDL_Texture *rect_t=SDL_CreateTextureFromSurface(renderer,rect_s);
    SDL_QueryTexture(rect_t,NULL,NULL,&rect.w,&rect.h);
    SDL_RenderCopy(renderer, rect_t, NULL, &rect);
}

void restart_end(int n)
{
    //background color
    SDL_SetRenderDrawColor(renderer,240,219,170,0.8);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    if (n<3)
    {
        //Game over
        SDL_Surface *title1_s=IMG_Load("image/Game over.png");
        SDL_Texture *title1_t=SDL_CreateTextureFromSurface(renderer,title1_s);
        SDL_QueryTexture(title1_t,NULL,NULL,&title1.w,&title1.h);
        SDL_RenderCopy(renderer, title1_t, NULL, &title1);
    }else
    {
        //You won
        SDL_Surface *title2_s=IMG_Load("image/You won.png");
        SDL_Texture *title2_t=SDL_CreateTextureFromSurface(renderer,title2_s);
        SDL_QueryTexture(title2_t,NULL,NULL,&title2.w,&title2.h);
        SDL_RenderCopy(renderer, title2_t, NULL, &title2);
    }
    //end button
    SDL_Surface *end_s=IMG_Load("image/end.png");
    SDL_Texture *end_t=SDL_CreateTextureFromSurface(renderer,end_s);
    SDL_QueryTexture(end_t,NULL,NULL,&end.w,&end.h);
    SDL_RenderCopy(renderer, end_t, NULL, &end);
    //restart button
    SDL_Surface *restart_s=IMG_Load("image/restart.png");
    SDL_Texture *restart_t=SDL_CreateTextureFromSurface(renderer,restart_s);
    SDL_QueryTexture(restart_t,NULL,NULL,&restart.w,&restart.h);
    SDL_RenderCopy(renderer, restart_t, NULL, &restart);
}

void continue_end ()
{
    //background color
    SDL_SetRenderDrawColor(renderer,240,219,170,0.8);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    //Menu pause
    SDL_Surface *title_s=IMG_Load("image/menu pause.png");
    SDL_Texture *title_t=SDL_CreateTextureFromSurface(renderer,title_s);
    SDL_QueryTexture(title_t,NULL,NULL,&title.w,&title.h);
    SDL_RenderCopy(renderer, title_t, NULL, &title);
    //resume
    SDL_Surface *resume_s=IMG_Load("image/resume.png");
    SDL_Texture *resume_t=SDL_CreateTextureFromSurface(renderer,resume_s);
    SDL_QueryTexture(resume_t,NULL,NULL,&resume.w,&resume.h);
    SDL_RenderCopy(renderer, resume_t, NULL, &resume);
    //back to menu
    SDL_Surface *back_to_menu_s=IMG_Load("image/back to menu.png");
    SDL_Texture *back_to_menu_t=SDL_CreateTextureFromSurface(renderer,back_to_menu_s);
    SDL_QueryTexture(back_to_menu_t,NULL,NULL,&back_to_menu.w,&back_to_menu.h);
    SDL_RenderCopy(renderer, back_to_menu_t, NULL, &back_to_menu);
    //Exit
    SDL_Surface *Exit_s=IMG_Load("image/Exit.png");
    SDL_Texture *Exit_t=SDL_CreateTextureFromSurface(renderer,Exit_s);
    SDL_QueryTexture(Exit_t,NULL,NULL,&Exit.w,&Exit.h);
    SDL_RenderCopy(renderer, Exit_t, NULL, &Exit);
    //render present
    SDL_RenderPresent(renderer);
}

void SDL_addiagonals(SDL_Renderer *renderer,int matrice[8][8],int size/*size of matrice*/)
{
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    for (int i =0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if(matrice[i][j]==1)
                diagonal_1(i,j,size);
            if(matrice[i][j]==2)
                diagonal_2(i,j,size);
        }
    }

}
void diagonal_1(int i, int j, int size)
{
    int n=board_size/size;
    SDL_RenderDrawLine(renderer,board.x+((j+1)*n),board.y+(i*n),board.x+(j*n),board.y+((i+1)*n));


}
void diagonal_2(int i, int j,int size)
{
    int n=board_size/size;
    SDL_RenderDrawLine(renderer,board.x+(j*n),board.y+(i*n),board.x+((j+1)*n),board.y+((i+1)*n));

}
void makeGrid(int n)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set the drawing color to black

    int case_size=board_size/n;

    for (int i=0;i<n+1;i++) {//horizonal lines
        SDL_RenderDrawLine(renderer,board.x,board.y+(case_size*i),board.x+board_size,board.y+(case_size*i));
    }

    for (int i=0;i<n+1;i++) {//vertical lines
        SDL_RenderDrawLine(renderer,board.x+(case_size*i),board.y,board.x+(case_size*i),board.y+board_size);
    }

}

//dessigne les cases des positions
void SDL_Pos(int size)
{
    //int radius=10;
    int n=board_size/size;
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    for(int i=0;i<size;i++)/*bottom ligne==y:size*/
    {

        SDL_Rect pos_tab={
    .x=board.x+(n/2)-10+(n*i),
    .y= board.y+board_size,
    .h=20,
    .w=20,
    };

       SDL_RenderDrawRect(renderer,&pos_tab);/*board.x+((n/2)+n*i),board.y+board_size+30*/
       }


    for(int i=0;i<size;i++)/*top ligne == y:-1*/
    {
        SDL_Rect pos_tab={
    .x=board.x+(n/2)-10+(n*i),
    .y= board.y-20,
    .h=20,
    .w=20,
    };

       SDL_RenderDrawRect(renderer,&pos_tab);/*,board.x+((n/2)+n*i),board.y-30*/

    }


    for(int i=0;i<size;i++)/*left colomn==x=-1*/
    {
        SDL_Rect pos_tab={
    .x=board.x-20,
    .y= board.y+(n/2)-10+(n*i),
    .h=20,
    .w=20,
    };

       SDL_RenderDrawRect(renderer,&pos_tab);/*board.x-30,board.y+(n/2)+(n*i)*/

    }


    for(int i=0;i<size;i++)/*right colomn==x:size*/
    {
        SDL_Rect pos_tab={
    .x=board.x+board_size,
    .y= board.y+(n/2)-10+(n*i),
    .h=20,
    .w=20,
    };

       SDL_RenderDrawRect(renderer,&pos_tab);/*radius,board.x+30+board_size,board.y+(n/2)+(n*i)*///


    }

}

//listens for click 3la wahda men pos rectangles
pos Get_pos(SDL_Event event,int size)
{
    const int  MAX_SIZE=8;
    pos position;
    int n=board_size/size;
    SDL_Rect pos_insert_rec = {0, 0, 0, 0};;
    SDL_Rect topRects[MAX_SIZE];
    SDL_Rect bottomRects[MAX_SIZE];
    SDL_Rect leftRects[MAX_SIZE];
    SDL_Rect rightRects[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        // Top side rectangles
        topRects[i].x = board.x+(n/2)-10+(n*i);
        topRects[i].y = board.y-20;
        topRects[i].w = 20;
        topRects[i].h = 20;

        // Bottom side rectangles
        bottomRects[i].x = board.x+(n/2)-10+(n*i);
        bottomRects[i].y = board.y+board_size ;
        bottomRects[i].w = 20;
        bottomRects[i].h = 20;

        // Left side rectangles
        leftRects[i].x = board.x-20;
        leftRects[i].y = board.y+(n/2)-10+(n*i);
        leftRects[i].w = 20;
        leftRects[i].h = 20;

        // Right side rectangles
        rightRects[i].x = board.x+board_size;
        rightRects[i].y = board.y+(n/2)-10+(n*i);
        rightRects[i].w = 20;
        rightRects[i].h = 20;
    }
    for (int i = 0; i < size; i++) {
                         if (withinrec(event, topRects[i])){position.y=-1;position.x=i;break;}
                          if (withinrec(event, bottomRects[i])){position.y=size;position.x=i;break;}
                          if (withinrec(event, leftRects[i]) ) {position.y=i;position.x=-1;break;}
                          if (withinrec(event, rightRects[i]))  {position.y=i;position.x=size;break;}
    }

    return position;
}

//ta3tilha pos w hia tersem corresponding rect
void Render_pos(pos position,int size,Uint8 r,Uint8 g,Uint8 b,Uint8 alpha)
{
    int n=board_size/size;
    SDL_Rect
    pos_tab=
    {
        .x=board.x + (position.x * n) ,
        .y= board.y + (position.y * n),
        .h=20,
        .w=20,
    };
      if (position.x == size) {
        pos_tab.y = pos_tab.y + (n / 2) - 10;
        pos_tab.x= board.x + board_size;
    } else if (position.x == -1) {
        pos_tab.x = pos_tab.x + n - 20;
        pos_tab.y = pos_tab.y + (n / 2) - 10;
    }

    if (position.y == size) {
        pos_tab.x = pos_tab.x + (n / 2) - 10;
        pos_tab.y = board.y+board_size ;
    } else if (position.y == -1) {
        pos_tab.x = pos_tab.x + (n / 2) - 10;
        pos_tab.y=pos_tab.y-(position.y * n)-20;
    }
    SDL_SetRenderDrawColor(renderer,r,g,b,alpha);
    SDL_RenderFillRect(renderer,&pos_tab);
}
void load_lvl(int *size,int *nbrdiagonal,bool win,int *tries,int matrice,pos *pos_init,pos* pos_final,Uint32* startTime,pos *pos_insert,int *score)
{
    int lvl=(*size)-2;
    int partie=(*nbrdiagonal)-(*size)+1;
                    (*tries)++;
                    if((*tries)<3)
                    {
                      if(win)//if win
                    {  (*tries)=0;
                     printf("win/////");
                       (*nbrdiagonal)++;partie++; *score=*score + 2;
                    if((*nbrdiagonal)>=(((*size)*(*size))/3)+3)
                       {(*size)++;(*nbrdiagonal)=((*size)*(*size))/3;*score = *score+10;}
                    if(lvl>5)
                        {printf("you have won the game");
                        //fplaset shutdown w return function user interface ta3ti choix ta3 n3awed nl3eb m niveax lwl
                        }

                    reset(matrice,*size,*size);
                    add_diagonals(matrice,*nbrdiagonal,*size,*size);
                    affich_matrice(matrice,*size,*size);
                    *pos_init=randomizePosInit(*size);
                     printf("x:%d",(*pos_init).x);
                    printf("y:%d\n",(*pos_init).y);
                    (*pos_final)=NavigateMatrix(matrice,(*pos_init),*size);
                     printf("final;x:%d",(*pos_final).x);
                    printf("final;y:%d\n",(*pos_final).y);
                    *startTime=SDL_GetTicks();
                   (*pos_insert).x=-10;
                    Render_pos((*pos_final),*size,0,255,0,255);
                    }
                    else// !win
                    {
                        printf("///worng///");

                        (*pos_insert).x=-10;
                        *startTime=SDL_GetTicks();
                    }
                    }
                    else//third try
                    {
                      (*nbrdiagonal)--;partie--;
                    if(partie<1)
                        {(*size)--;lvl--;}
                    if(lvl<1)
                       {
                         printf("game over");
                         //function sdl user interface y3tili choix bach n3awed nl3eb
                       }
                    else
                        {
                            (*tries)=0;
                        reset(matrice,*size,*size);
                    add_diagonals(matrice,*nbrdiagonal,*size,*size);
                    affich_matrice(matrice,*size,*size);
                    *pos_init=randomizePosInit(*size);
                     printf("x:%d",(*pos_init).x);
                    printf("y:%d\n",(*pos_init).y);
                    (*pos_final)=NavigateMatrix(matrice,(*pos_init),*size);
                     printf("final;x:%d",(*pos_final).x);
                    printf("final;y:%d\n",(*pos_final).y);
                    *startTime=SDL_GetTicks();
                   (*pos_insert).x=-10;
                        }

                    }


}

color get_color(int x,int y)
 {

        color c;
        Uint32 pixel;
        SDL_RenderReadPixels(renderer, &(SDL_Rect){x, y, 1, 1}, SDL_PIXELFORMAT_RGBA8888, &pixel, sizeof(Uint32));
        Uint8 red=0, green=0, blue=0, alpha=0;
        SDL_GetRGBA(pixel, SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), &red, &green, &blue, &alpha);
        c.a=alpha;c.b=blue;c.g=green;c.r=red;
        return c;

 }
void machine_creat_matrice(int matriceM[8][8],int size)
{
    int case_size=board_size/size;
    color color_middle,color_diag_1,color_middle6;
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            color_middle6= get_color(board.x+38+(i*case_size),board.y+(case_size/2)+(j*case_size));
            color_middle= get_color(board.x+(case_size/2)+(i*case_size),board.y+(case_size/2)+(j*case_size));
            if (color_middle.a==255 &&color_middle.r==0 && color_middle.g==0 &&color_middle.b==0 ||
                color_middle6.a==255 &&color_middle6.r==0 && color_middle6.g==0 &&color_middle6.b==0  )
            {
               if(size==6) color_diag_1=get_color(board.x+38+(i*case_size)+1,board.y+(case_size/2)+(j*case_size)-1);
                else color_diag_1=get_color(board.x+(case_size/2)+(i*case_size)+1,board.y+(case_size/2)+(j*case_size)-1);
                if(color_diag_1.a==255 &&color_diag_1.r==0 && color_diag_1.g==0 &&color_diag_1.b==0)
                    {matriceM[j][i]=1;}
                else matriceM[j][i]=2;
            }
            else
            {matriceM[j][i]=0;}
        }
    }
}


void Shutdown(void){
    if(renderer){
    SDL_DestroyRenderer(renderer);
    }
    if(window){
    SDL_DestroyWindow(window);
    }
    SDL_Quit();

}
