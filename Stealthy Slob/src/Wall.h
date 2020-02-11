#pragma once
#ifndef __WALL__
#define __WALL__

#include "GameObjectType.h"
#include "TextureManager.h"

class Wall{
public:
	Wall(SDL_Rect position); //parameter to be obtained from level manager
	~Wall();
	SDL_Rect* m_getRect();
	GameObjectType m_getType();
private:
	SDL_Rect m_dst;
	GameObjectType m_type;
};
#endif /* defined (__WALL__) */