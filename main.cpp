#include<SDL/SDL_mixer.h>
#include "snake.h"


int main()
{
    bool running;
    int fps;
    Mix_Music *music;
    snake s(840,640,20);
    Uint32 start;


    while(1)
    {

        s.Init();
        fps=6;
    //Intro

        Mix_OpenAudio(22050,AUDIO_S16SYS,2,128);
        music=Mix_LoadMUS("assets/music/stronger.mp3");
        Mix_PlayMusic(music,-1);
        music=Mix_LoadMUS("assets/music/snake.wav");
        s.Draw_Bg();
        s.WaitKey();
        Mix_PlayMusic(music,-1);
        s.Draw_Bg();
        s.Ready();
        s.Fill_Screen();
        SDL_Delay(2000);
        running=true;

        while(running)
        {

            start=SDL_GetTicks();
            running=s.Go_To();
            s.Draw_Bg();
            s.Draw_Border();
            s.Draw_Score();
            s.Draw_Food(&fps);
            s.Draw_Node();
            s.Fill_Screen();

            if(1000/fps>(int)(SDL_GetTicks()-start))
                SDL_Delay(1000/fps -SDL_GetTicks() +start);

        }

        Mix_FreeMusic(music);
        music=Mix_LoadMUS("assets/music/game_over.wav");
        Mix_PlayMusic(music,-1);

        SDL_Delay(800);
        s.Draw_Bg();
        s.Game_Over();
        s.Fill_Screen();
        SDL_Delay(4000);
        Mix_FreeMusic(music);
        Mix_CloseAudio();
    }


}
