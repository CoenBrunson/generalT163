#pragma once
#ifndef __LEVEL__
#define __LEVEL__

#include<vector>
#include<algorithm>
#include"GameObject.h"
#include"Player.h"
#include"Enemy.h"
#include"Wall.h"
#include"Pit.h"
#include"Level.h"
#include <glm\vec2.hpp>
#include "CollisionManager.h"

class Level {
public:
	Level(int level);
	~Level();
	int getPitCount();
	int getWallCount();
	int getEnemyCount();
	Pit* getPits();
	Wall* getWalls();
	glm::vec2* getEnemyPatrols();
	void loadLevel(int level);
	void draw(SDL_Renderer* m_pRenderer);
	void clearLevel();
	Player* getPlayer();
	void update();
	void killPlayer();
	bool checkPlayerBounds();
private:
	int m_enemyCount, m_pitCount, m_wallCount;
	Player* m_player;
	std::vector<Pit*> m_pits;
	std::vector<Wall*> m_walls;
	std::vector<Enemy*> m_pEnemies;
	std::vector<std::vector<glm::vec2>> m_enemyPatrols;
	glm::vec2 m_playerSpawn;
	SDL_Rect* m_background;
	std::vector < glm::vec2> e1Points;
	std::vector < glm::vec2> e2Points;
	std::vector < glm::vec2> e3Points;
};

#endif