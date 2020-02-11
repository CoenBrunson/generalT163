#include "Pit.h"
#include "Game.h"

Pit::Pit(SDL_Rect outerPosition)
{
	TheTextureManager::Instance()->load("../Assets/textures/pit.png", "pit", TheGame::Instance()->getRenderer());
	m_outer = outerPosition;
	m_inner.x = m_outer.x - 10;
	m_inner.y = m_outer.y + 10;
	m_inner.w = m_outer.w - 20;
	m_inner.h = m_outer.h - 20;
}

Pit::~Pit()
{
}

SDL_Rect* Pit::m_getDisplayRect()
{
	return &m_outer;
}

/*void Pit::draw()
{
	TheTextureManager::Instance()->draw("pit", m_outer.x, m_outer.y, TheGame::Instance()->getRenderer(), false);
}*/

SDL_Rect* Pit::m_getCollisionRect()
{
	return &m_inner;
}

GameObjectType Pit::m_getType()
{
	return m_type;
}
