#include <iostream>
#include <fstream>

using namespace std;

char map[15][8];

struct Point {
	int x; int y;
};

enum Type {
	Player,
	Enemy,
	Item
};
enum EnemyType {
	Goblin,
	Guard,
	Gigant
};
enum ItemType {
	Heal,
	DamageBoost
};



struct Entity {
	char symbol;
	Point position;
	string Type;

	//enemies
	int hp_enemy;
	EnemyType enemyType;

	//items 
	ItemType itemType;
	int effect;

	//player
	int hp_player = 0;
	int damage = 0;

};

Entity createGoblin(int x, int y) {
	Entity goblin;
	goblin.symbol = 'G';
	goblin.position = { x,y };
	goblin.Type = Type::Enemy;
	goblin.enemyType = EnemyType::Goblin;
	goblin.hp_enemy = 5;
	return goblin;
}

Entity createGigant(int x, int y) {
	Entity gigant;
	gigant.symbol = 'B';
	gigant.position = { x,y };
	gigant.Type = Type::Enemy;
	gigant.enemyType = EnemyType::Gigant;
	gigant.hp_enemy = 20;
	return gigant;
}

Entity createGuard(int x, int y) {
	Entity guard;
	guard.symbol = 'I';
	guard.position = { x,y };
	guard.Type = Type::Enemy;
	guard.enemyType = EnemyType::Guard;
	guard.hp_enemy = 10;
	return guard;
}

Entity createPlayer(int x, int y) {
	Entity player;
	player.symbol = 'P';
	player.position = { 0,4 };
	player.Type = Type::Player;
	player.hp_player = 20;
	return player;
}

Entity createHeal(int x, int y) {
	Entity heal;
	heal.symbol = 'H';
	heal.position = { x,y };
	heal.Type = Type::Item;
	heal.itemType = ItemType::Heal;
	return heal;
}

Entity createDB(int x, int y) {
	Entity damage_boost;
	damage_boost.symbol = 'D';
	damage_boost.position = { x,y };
	damage_boost.Type = Type::Item;
	damage_boost.itemType = ItemType::DamageBoost;
	return damage_boost;
}


void drawMap() {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 15; x++) {
			map[x][y] = '~';
			cout << map[x][y];
		}
		cout << endl;
	}
}

void drawPlayer() {
	
}

int main() {
	drawMap();

	return 0;
}
