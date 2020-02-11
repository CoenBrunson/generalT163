#pragma once
#ifndef __LevelManager__
#define __LevelManager__

#include<vector>
#include<algorithm>
#include"GameObject.h"
#include"Player.h"
#include"Enemy.h"
#include"Wall.h"
#include"Pit.h"
#include"Level.h"
#include <glm\vec2.hpp>

class LevelManager {
private:
	static LevelManager* s_pInstance;
	Level* m_currentLevel;
public:
	static LevelManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new LevelManager();
			return s_pInstance;
		}

		return s_pInstance;
	}
	LevelManager();
	~LevelManager();
	void loadLevel(int level);
};
#endif