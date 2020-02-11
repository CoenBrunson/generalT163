#include "Wall.h"

Wall::Wall(SDL_Rect position)
{
	m_dst = position;
	m_type = WALL;
}

SDL_Rect *Wall::m_getRect()
{
	return &m_dst;
}

GameObjectType Wall::m_getType()
{
	return m_type;
}
