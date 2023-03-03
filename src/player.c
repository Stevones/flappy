#include "raylib.h"
#include "flappy.h"
#include <stdio.h>




void setValuePlayer(Player *flappy) {
	flappy->x = screenWidth/7;
    flappy->y = screenHeight/2 - 25;
    flappy->radius = 25;
    
}





void updatePlayerPosition(Player *flappy, Rectangle *pipe[]) {
	if (IsKeyDown(KEY_SPACE)) {
        flappy->y -= 3;
    }
    else {
        flappy->y += 3;
    }

    if (flappy->y > screenHeight + 125 || flappy->y < -126) {
        lost = true;
    }




    }


