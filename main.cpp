﻿#include <iostream>
#include <raylib.h>
#include "Tile.h"
#include "GameGrid.h"
#include "Pathfinding.h"
#include "Controls.h"
#include "Enemy.h"


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Pathfinding Grid");
    SetTargetFPS(60);

    Grid grid(20,20);
    Tile* goalTile = nullptr;

    Tile* startTile = grid.GetTilePos(0, 0);
    Enemy enemy(startTile);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);


        MouseClick(grid, goalTile);
        KeyPress(grid, startTile, goalTile, enemy);

        enemy.MoveConstantly();

        grid.DrawGrid();
        enemy.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
