#include"Level.h"

Level::Level(int level)
{
	loadLevel(level);
}

int Level::getPitCount()
{
	return m_pitCount;
}

int Level::getEnemyCount()
{
	return m_enemyCount;
}

Pit* Level::getPits()
{
	return m_pits[0];
}

Wall* Level::getWalls()
{
	return m_walls[0];
}

glm::vec2* Level::getEnemyPatrols()
{
	return &m_enemyPatrols[0][0];
}

void Level::loadLevel(int level) {
	switch (level) {
	case 0:
		m_player = new Player();
		m_player->setPosition(glm::vec2(50.0f, 50.0f));
		m_player->resetNewPosition();
		m_player->setCollisionRadius(20);

		m_background = new SDL_Rect({ 0, 0, 1280, 720 });
		m_enemyCount = 3;
		m_wallCount = 13;
		m_pitCount = 5;

		m_walls.push_back(new Wall({ 0, 0, 1280, 10 }));
		m_walls.push_back(new Wall({ 0, 710, 1280, 10 }));
		m_walls.push_back(new Wall({ 0, 0, 10, 720 }));
		m_walls.push_back(new Wall({ 1270, 0, 10, 720 }));
		m_walls.push_back(new Wall({ 120, 80, 650, 20 }));
		m_walls.push_back(new Wall({ 755, 80, 15, 500 }));
		m_walls.push_back(new Wall({ 0, 390, 680, 25 }));
		m_walls.push_back(new Wall({ 390, 170, 40, 135 }));
		m_walls.push_back(new Wall({ 850, 80, 350, 20 }));
		m_walls.push_back(new Wall({ 850, 170, 20, 245 }));
		m_walls.push_back(new Wall({ 1180, 170, 20, 245 }));
		m_walls.push_back(new Wall({ 850, 480, 350, 20 }));
		m_walls.push_back(new Wall({ 755, 640, 15, 80 }));

		m_pits.push_back(new Pit({ 520, 170, 155, 135 }));
		m_pits.push_back(new Pit({ 130, 170, 155, 135 }));
		m_pits.push_back(new Pit({ 135, 500, 545, 140 }));
		m_pits.push_back(new Pit({ 960, 165, 130, 260 }));
		m_pits.push_back(new Pit({ 855, 555, 170, 110 }));

		e1Points.push_back(glm::vec2(310, 120));
		e1Points.push_back(glm::vec2(310, 320));
		e1Points.push_back(glm::vec2(100, 320));
		e1Points.push_back(glm::vec2(100, 120));
		e1Points.push_back(glm::vec2(0, 0));

		e2Points.push_back(glm::vec2(800, 180));
		e2Points.push_back(glm::vec2(800, 500));
		e2Points.push_back(glm::vec2(0, 0));

		e3Points.push_back(glm::vec2(800, 50));
		e3Points.push_back(glm::vec2(1220, 50));
		e3Points.push_back(glm::vec2(1220, 100));
		e3Points.push_back(glm::vec2(800, 100));
		e3Points.push_back(glm::vec2(0, 0));

		m_pEnemies.push_back(new Enemy(e1Points));
		m_pEnemies.push_back(new Enemy(e2Points));
		m_pEnemies.push_back(new Enemy(e3Points));
		break;
	default:
		std::cout << "Error: No Level Specified";
		return;
	}
}

void Level::clearLevel() {
	m_walls.clear();
	m_pits.clear();
	m_pEnemies.clear();
	m_walls.shrink_to_fit();
	m_pits.shrink_to_fit();
	m_pEnemies.shrink_to_fit();
	delete(m_player);
}

Player* Level::getPlayer()
{
	return m_player;
}

void Level::update()
{
	if (m_player->heartBeatCheck()) {
		m_player->calcNewPosition();
		if (checkPlayerBounds()) {
			m_player->m_move();
		}
		else m_player->resetNewPosition();
	}
	for (int i = 0; i < (int)m_pEnemies.size(); i++)
	{
		m_pEnemies[i]->update();
	}
}

void Level::draw(SDL_Renderer* m_pRenderer)
{
	SDL_SetRenderDrawColor(m_pRenderer, 128, 128, 128, 255);
	SDL_RenderFillRect(m_pRenderer, m_background);
	SDL_SetRenderDrawColor(m_pRenderer, 32, 32, 32, 255);
	for (auto& i : m_walls) {
		SDL_RenderFillRect(m_pRenderer, i->m_getRect());
	}
	SDL_SetRenderDrawColor(m_pRenderer, 102, 0, 0, 255);
	for (auto& i : m_pits) {
		SDL_RenderFillRect(m_pRenderer, i->m_getDisplayRect());
	}
	for (int i = 0; i < (int)m_pEnemies.size(); i++)
	{
		m_pEnemies[i]->draw();
	}
	if (m_player->heartBeatCheck()) {
		m_player->draw();
		m_player->drawLamp();
	}
}

bool Level::checkPlayerBounds()
{
	for (int i = 0; i < m_wallCount; i++)
	{
		if (CollisionManager::CircleToRectCollision(m_player, m_walls[i]->m_getRect()))
		{
			return false;
		}
	}
	for (int i = 0; i < m_pitCount; i++)
	{
		if (CollisionManager::CircleToRectCollision(m_player, m_pits[i]->m_getCollisionRect()))
		{
			m_player->kill();
			return false;
		}
	}
	for (int i = 0; i < m_enemyCount; i++)
	{
		if (CollisionManager::CircleToCircleCollistion(m_player, m_pEnemies[i]))
		{
			m_player->kill();
			return false;
		}
	}
	return true;
}
