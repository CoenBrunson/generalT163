#pragma once
#ifndef __PIT__
#define __PIT__

#include "GameObjectType.h"
#include "TextureManager.h"

class Pit{
public:
	Pit(SDL_Rect outerPosition); //parameter to be obtained from level manager
	~Pit();
	SDL_Rect* m_getDisplayRect();
	SDL_Rect* m_getCollisionRect();
	GameObjectType m_getType();
private:
	SDL_Rect m_outer, m_inner;
	GameObjectType m_type;
};
#endif /* defined (__PIT__) */