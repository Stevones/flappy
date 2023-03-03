#ifndef __FLAPPY_H
#define __FLAPPY_H


typedef struct Player {
    int x;
    int y;
    int radius;

} Player;


typedef struct Pipe {

    

} Pipe;


void updatePlayerPosition(Player *flappy, Rectangle *pipe[]);
void setValuePlayer(Player *flappy);
void updatePipePosition(Rectangle *pipe[], Rectangle *pipeBottom[]);
void setValuePipe(Rectangle *pipe[], Rectangle Pipe[], Rectangle *pipeBottom[], Rectangle PipeBottom[]);


extern int screenWidth;
extern int screenHeight;
extern int maxTubes;
extern int score;
extern char scoreLabel[];
extern bool lost;







#endif

