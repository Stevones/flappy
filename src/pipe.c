#include "raylib.h"
#include "flappy.h"


void setValuePipe(Rectangle *pipe[], Rectangle Pipe[], Rectangle *pipeBottom[], Rectangle PipeBottom[]) {
	for (int i = 0; i < maxTubes; i++) {
        pipe[i] = &Pipe[i];
        if (i == 0) {
        pipe[i]->x = screenWidth;
    }
    else {
        pipe[i]->x = pipe[i - 1]->x + pipe[i - 1]->width + (GetRandomValue(80, 200));
    }
    	pipe[i]->y = 0;
    	pipe[i]->width = 50;
    	pipe[i]->height = GetRandomValue(75, 225);
        // Bottom
        pipeBottom[i] = &PipeBottom[i];
        pipeBottom[i]->height = (screenHeight - pipe[i]->height) - 150;
        pipeBottom[i]->x = pipe[i]->x;
        pipeBottom[i]->y = screenHeight - pipeBottom[i]->height;
        pipeBottom[i]->width = pipe[i]->width;






    }




}

void updatePipePosition(Rectangle *pipe[], Rectangle *pipeBottom[]) {
	for (int i = 0; i < maxTubes; i++) {
    pipe[i]->x -= 3;
    pipeBottom[i]->x -= 3;
}

}
