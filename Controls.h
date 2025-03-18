﻿#pragma once
#include "GameGrid.h"
#include "Enemy.h"
#include "Pathfinding.h"
#include "raylib.h"

void ChangeTile(Grid& grid, Tile*& goalTile);
void StartMovement(Grid& grid, Tile*& startTile, Tile*& goalTile, Enemy& enemy);
void GenerateEnemy(Tile*& startTile, Tile*& goalTile, Enemy*& enemy);