#include "snake.h"



snake::snake(int width,int height,int l)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    screen=SDL_SetVideoMode(width,height,24,SDL_HWSURFACE|SDL_ASYNCBLIT);

    TTF_Init();
    font=TTF_OpenFont("assets/font/journal.ttf",100);
    color.b=color.g=color.r=0;
    text=TTF_RenderText_Solid(font,"Ready ...",color);

    this->width=width;
    this->height=height;
    this->l=l;

    R_Food.x=l*F_Rand(width/l -1);
    R_Food.y=l*F_Rand(height/l -1);
    R_Food.h=R_Food.w=l;

    background=SDL_LoadBMP("assets/images/background.bmp");
    noeud=SDL_DisplayFormat(SDL_LoadBMP("assets/images/node.bmp"));
    food=SDL_DisplayFormat(SDL_LoadBMP("assets/images/food.bmp"));

    SDL_SetColorKey(noeud,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0xff,0,0));
    SDL_SetColorKey(food,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0,0,0xff));

    Bor_Color=SDL_MapRGB(screen->format,0,0x88,0);



}

int snake::F_Rand(int x)
{   bool c=true;
    int r;
    while(c)
    {
        srand(time(NULL));
        r=rand();
        r=r%x;
        if(r>1)
        return r;
        return 2;

    }
    return 2;
}



bool snake::Eated()
{
    if(first->Get_Sqr()->x==R_Food.x && first->Get_Sqr()->y==R_Food.y)
    {
        score+=addscore;
        addscore+=5;
        return true;
    }
        return false;
}


void snake::Init()
{
    score=0;
    addscore=5;
    while(SDL_PollEvent(&event));
    first=new node(width/2,height/2,l,0);
    for(int i=0;i<4;i++)
        first->Add_Node(l);
}


void snake::Ready()
{


    text=TTF_RenderText_Solid(font,"Ready ...",color);
    R_Food.x=R_Food.y=100;
    SDL_BlitSurface(text,NULL,screen,&R_Food);

}

void snake::Game_Over()
{

    text=TTF_RenderText_Solid(font,"Game Over :( ...",color);
    R_Food.x=R_Food.y=100;
    SDL_BlitSurface(text,NULL,screen,&R_Food);
    while(SDL_PollEvent(&event));
}

void snake::WaitKey()
{

    text=TTF_RenderText_Solid(font,"Press any key to play...",color);
    R_Food.x=R_Food.y=100;
    SDL_BlitSurface(text,NULL,screen,&R_Food);
    SDL_Flip(screen);
    SDL_WaitEvent(&event);
}


void snake::Draw_Score()
{
    char w[20];
    sprintf(w,"Score :%d",score);
    scor=TTF_RenderText_Solid(font,w,color);
    SDL_BlitSurface(scor,NULL,screen,NULL);
}

void snake::Draw_Bg()
{
    SDL_BlitSurface(background,NULL,screen,NULL);
}


void snake:: Draw_Node()
{
    node* p=first;

    while(p)
    {
        SDL_BlitSurface(noeud,NULL,screen,p->Get_Sqr());
        p=p->Get_Next();
    }
}


bool snake:: Go_To()
{

if(!first->Move_On(l))
                return false;

   while(SDL_PollEvent(&event))
    {
            switch (event.type)
                {
                    case SDL_QUIT: exit(0);break;
                    case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                        {
                            case SDLK_UP: first-> Go_Up();return true;
                            case SDLK_DOWN: first-> Go_Down(); return true;
                            case SDLK_LEFT: first-> Go_Left(); return true;
                            case SDLK_RIGHT: first-> Go_Right(); return true;
                            default: break;
                        }   break;
                default: break;
                }
      }
         return true;
}


void snake::Draw_Food(int* fps)
{
    SDL_BlitSurface(food,NULL,screen,&R_Food);
    if(Eated())
        {
            first->Add_Node(l);
            R_Food.x=l*F_Rand(width/l -1);
            R_Food.y=l*F_Rand(height/l -1);
            *fps=2+*fps;

        }
}

void snake::Draw_Border()
{
    Bor.x=Bor.y=0;
    Bor.w=Bor.h=20;
    int i;
    //UP
    for(i=0;i<42;i++)
        {
            SDL_FillRect(screen,&Bor,Bor_Color);
            Bor.x+=20;
        }
    //RIGHT
    Bor.x=0;
    for(i=0;i<31;i++)
        {
            SDL_FillRect(screen,&Bor,Bor_Color);
            Bor.y+=20;
        }
    //DOWN
    Bor.x=0;
    for(i=0;i<41;i++)
        {
            SDL_FillRect(screen,&Bor,Bor_Color);
            Bor.x+=20;
        }

     //LEFT
     Bor.y=0;
     for(i=0;i<32;i++)
        {
            SDL_FillRect(screen,&Bor,Bor_Color);
            Bor.y+=20;
        }
}



void snake::Fill_Screen()
{
    SDL_Flip(screen);
}

void snake::Free_Snake()
{
    node* temp,*p;
    temp=first;
    while(temp)
    {
        p=p->Get_Next();
        delete temp;
        temp=p;
    }
}


snake::~snake()
{
    Free_Snake();
    TTF_Quit();
    SDL_Quit();
}
