﻿#include "Controls.h"
#include "GameGrid.h"
#include "Enemy.h"
#include "Pathfinding.h"
#include "raylib.h"


void MouseClick(Grid& grid, Tile*& goalTile)
{
    Vector2 mousePos = GetMousePosition();
    int row = mousePos.y / Tile::SIZE;
    int col = mousePos.x / Tile::SIZE;

    Tile* clickedTile = grid.GetTilePos(row, col);


    if (clickedTile)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (goalTile)
            {
                goalTile->terrainType = GRASS;
                goalTile->tileColor = terrainColors[GRASS];
            }

            clickedTile->terrainType = GOAL;
            clickedTile->tileColor = terrainColors[GOAL];
            goalTile = clickedTile;
        }
        else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            clickedTile->terrainType = WATER;
            clickedTile->tileColor = terrainColors[WATER];
            clickedTile->isWalkable = false;
        }
    }
}

void KeyPress(Grid& grid, Tile*& startTile, Tile*& goalTile, Enemy& enemy)
{
    if (IsKeyPressed(KEY_SPACE))
    {
        grid.ResetTiles();
        startTile = grid.GetTilePos(0, 0);

        if (startTile && goalTile)
        {
            BFS(grid, startTile, goalTile);
            enemy.SetTile(startTile);
        }
    }
}